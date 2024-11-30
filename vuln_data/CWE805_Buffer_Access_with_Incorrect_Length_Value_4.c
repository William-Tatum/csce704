#include <stdio.h>
#include <string.h>

void unsafe_copy(char *source, size_t length) {
    char buffer[10];
    if (length > sizeof(buffer)) {
        printf("Error: Length exceeds buffer size\n");
        return;
    }
    memcpy(buffer, source, length);
    printf("Buffer content: %.*s\n", (int)length, buffer);
}

int main() {
    char input[] = "This is a long string";
    unsafe_copy(input, 25);
    return 0;
}