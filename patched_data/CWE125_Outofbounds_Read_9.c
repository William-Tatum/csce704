#include <stdio.h>
#include <string.h>

int main() {
    char buffer[11];
    strncpy(buffer, "HelloWorld", 10);
    buffer[10] = '\0';
    printf("Buffer content: %s\n", buffer);
    int index = 9;
    if (index >= 0 && index < sizeof(buffer) - 1) {
        char c = buffer[index];
        printf("Character at index %d: %c\n", index, c);
    } else {
        printf("Index %d is out-of-bounds\n", index);
    }
    return 0;
}