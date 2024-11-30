#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    
    if (file == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    
    // Other operations on the file assuming file is valid
    if (fclose(file) != 0) {
        perror("Failed to close file");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}