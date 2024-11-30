#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "12345");

    int index;
    printf("Enter an index to read from buffer: ");
    scanf("%d", &index);

    printf("Character at index %d: %c\n", index, buffer[index]);

    return 0;
}