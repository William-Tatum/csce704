#include <stdio.h>
#include <string.h>

void processInput(const char *input) {
    char buffer[100];
    size_t length = strlen(input);
    
    if (length >= sizeof(buffer)) {
        printf("Input too long!\n");
        return;
    }

    strcpy(buffer, input);
    
    if (buffer[length] == '\0') {
        printf("Processed input: %s\n", buffer);
    } else {
        printf("Error: Sentinel overwritten!\n");
    }
}

int main() {
    char userInput[150];
    printf("Enter a string: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = '\0';
    processInput(userInput);
    return 0;
}