#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *sensitive_data = malloc(100 * sizeof(char));
    if (sensitive_data == NULL) {
        perror("Failed to allocate memory");
        return -1;
    }

    strcpy(sensitive_data, "ThisIsASensitivePassword");

    char *temp = realloc(sensitive_data, 200 * sizeof(char));
    if (temp == NULL) {
        // Manually clear sensitive data from memory
        memset(sensitive_data, 0, 100 * sizeof(char));
        free(sensitive_data);
        perror("Failed to reallocate memory");
        return -1;
    }
    
    // Manually clear sensitive data from the old memory location
    memset(sensitive_data, 0, 100 * sizeof(char));

    sensitive_data = temp;
    
    // Additional operations...

    memset(sensitive_data, 0, 200 * sizeof(char));
    free(sensitive_data);
    return 0;
}