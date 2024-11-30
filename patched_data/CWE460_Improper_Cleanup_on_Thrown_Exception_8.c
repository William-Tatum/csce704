#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void cleanup(FILE *file, char *buffer) {
    if (buffer != NULL) {
        free(buffer);
    }
    if (file != NULL) {
        fclose(file);
    }
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    char *buffer = (char *)malloc(256);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return;
    }

    size_t bytesRead = fread(buffer, 1, 256, file);
    if (bytesRead == 0 && ferror(file)) {
        perror("Failed to read data");
        cleanup(file, buffer);
        return;
    }

    printf("File content processed successfully.\n");

    cleanup(file, buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    process_file(argv[1]);
    return EXIT_SUCCESS;
}