#include <stdio.h>
#include <string.h>

void bufferAccessIncorrectLengthValue(char *input) {
    char buffer[10];
    int length = strlen(input);

    for (int i = 0; i < length && i < sizeof(buffer) - 1; i++) {
        buffer[i] = input[i];
    }
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer: %s\n", buffer);
}

int main() {
    char input[] = "This input is too long for buffer";
    bufferAccessIncorrectLengthValue(input);
    return 0;
}