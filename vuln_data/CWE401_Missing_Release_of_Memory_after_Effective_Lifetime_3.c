#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(const char *data) {
    char *buffer = (char *)malloc(strlen(data) + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return;
    }

    strcpy(buffer, data);
    printf("Processed data: %s\n", buffer);

    free(buffer);
}

int main() {
    const char *input_data = "Example data";
    process_data(input_data);
    return 0;
}