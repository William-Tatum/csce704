#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void processData(char *input, int length) {
    if (length <= 0 || length > strlen(input)) {
        printf("Error: Invalid length parameter\n");
        return;
    }

    char *buffer = (char *)malloc(length);
    if (!buffer) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    strncpy(buffer, input, length);
    buffer[length - 1] = '\0';

    printf("Processed data: %s\n", buffer);
    free(buffer);
}

int main() {
    char input[100];
    int length;

    printf("Enter data: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter length: ");
    scanf("%d", &length);

    processData(input, length);
    return 0;
}