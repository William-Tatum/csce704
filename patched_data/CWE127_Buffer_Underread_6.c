#include <stdio.h>
#include <string.h>

void bufferUnderReadExample(char *input) {
    char buffer[10];
    if (strlen(input) < 10) {
        strcpy(buffer, input);
    } else {
        strncpy(buffer, input, 9);
        buffer[9] = '\0';
    }

    if (buffer + 5 >= buffer) {
        printf("Value: %c\n", *(buffer + 5));
    } else {
        printf("Read error: Out of bounds access attempted\n");
    }
}

int main() {
    char exampleInput[] = "example";
    bufferUnderReadExample(exampleInput);
    return 0;
}