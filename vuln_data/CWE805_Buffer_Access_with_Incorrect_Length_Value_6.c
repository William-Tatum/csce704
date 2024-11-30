#include <stdio.h>
#include <string.h>

void bufferAccessIncorrectLengthValue(char *input) {
    char buffer[10];
    int length = strlen(input); // Incorrect length value: no boundary check

    for (int i = 0; i < length; i++) {
        buffer[i] = input[i]; // Potential buffer overflow if length > 10
    }
    buffer[length] = '\0';
    printf("Buffer: %s\n", buffer);
}

int main() {
    char input[] = "This input is too long for buffer";
    bufferAccessIncorrectLengthValue(input);
    return 0;
}