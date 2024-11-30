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

    char *ptr = buffer + 5;
    ptr -= 6;  // Under-read occurs here
    
    printf("Value: %c\n", *ptr); // Attempting to read before buffer
}

int main() {
    char exampleInput[] = "example";
    bufferUnderReadExample(exampleInput);
    return 0;
}