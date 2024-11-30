#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void process_data(const char *data) {
    size_t data_length = strlen(data);
    char *buffer = (char *)malloc(data_length + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return;
    }
    strncpy(buffer, data, data_length);
    buffer[data_length] = '\0';

    if (strcmp(buffer, "special-case") == 0) {
        printf("Special case handled.\n");
    } else {
        printf("Data: %s\n", buffer);
    }

    free(buffer);
}

int main() {
    char data[] = "example data";
    for (int i = 0; i < 5; i++) {
        process_data(data);
    }

    return 0;
}