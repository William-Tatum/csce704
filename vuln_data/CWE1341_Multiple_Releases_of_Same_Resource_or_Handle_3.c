#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
    
    fprintf(file, "CWE-1341 example\n");

    if (fclose(file) != 0) {
        perror("Failed to close file");
        return 1;
    }

    // Incorrectly attempting to fclose the same file again
    if (fclose(file) != 0) {
        perror("Attempted to close the file again");
        return 1;
    }
    
    return 0;
}