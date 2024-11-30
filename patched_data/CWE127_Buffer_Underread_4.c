#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strncpy(buffer, "Hello", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    int index = -1;
    if (index >= 0 && index < sizeof(buffer) - 1) {
        printf("Char at index %d is: %c\n", index, buffer[index]);
    } else {
        printf("Invalid index access\n");
    }

    return 0;
}