#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void process_data(const char *data) {
    char *buffer = (char *)malloc(256);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return;
    }
    strncpy(buffer, data, 255);
    buffer[255] = '\0';

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