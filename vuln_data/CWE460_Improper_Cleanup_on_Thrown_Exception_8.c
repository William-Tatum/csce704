#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void cleanup(FILE *file) {
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
    
    bool error_occurred = false;
    char *buffer = (char *)malloc(256);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return;
    }

    if (fread(buffer, 1, 256, file) < 1) {
        perror("Failed to read data");
        error_occurred = true;
    }

    if (error_occurred) {
        free(buffer);
        fclose(file);
        return;
    }

    printf("File content processed successfully.\n");
    
    free(buffer);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    process_file(argv[1]);
    return EXIT_SUCCESS;
}