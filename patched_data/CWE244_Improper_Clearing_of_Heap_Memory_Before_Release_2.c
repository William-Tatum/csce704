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
        explicit_bzero(sensitive_data, 100 * sizeof(char));
        free(sensitive_data);
        perror("Failed to reallocate memory");
        return -1;
    }

    sensitive_data = temp;

    explicit_bzero(sensitive_data, 200 * sizeof(char));
    free(sensitive_data);
    return 0;
}