#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(const char *data) {
    size_t data_length = strlen(data) + 1;
    char *buffer = (char *)malloc(data_length);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return;
    }

    strncpy(buffer, data, data_length - 1);
    buffer[data_length - 1] = '\0';
    printf("Processed data: %s\n", buffer);

    free(buffer);
}

int main() {
    const char *input_data = "Example data";
    process_data(input_data);
    return 0;
}