#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(const char *source) {
    char *buffer = malloc(strlen(source) + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    
    strcpy(buffer, source);
    
    printf("Copied string: %s\n", buffer);
    
    free(buffer);
}

int main() {
    const char *text = "Use of sizeof can be tricky!";
    copyString(text);
    return 0;
}