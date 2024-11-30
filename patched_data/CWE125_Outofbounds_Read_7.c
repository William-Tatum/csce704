#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strncpy(buffer, "12345", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    int index;
    printf("Enter an index to read from buffer: ");
    if (scanf("%d", &index) != 1 || index < 0 || index >= strlen(buffer)) {
        printf("Invalid index.\n");
        return 1;
    }

    printf("Character at index %d: %c\n", index, buffer[index]);

    return 0;
}