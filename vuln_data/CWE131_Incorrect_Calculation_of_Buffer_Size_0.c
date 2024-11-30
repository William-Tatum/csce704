#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processInput(const char *input) {
    size_t length = strlen(input);
    char *buffer = (char *)malloc(length * sizeof(char));
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }
    
    strcpy(buffer, input);
    printf("Processed input: %s\n", buffer);
    
    free(buffer);
}

int main() {
    char data[100];
    printf("Enter some text: ");
    if (fgets(data, sizeof(data), stdin) != NULL) {
        processInput(data);
    }
    return 0;
}