#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
    
    fprintf(file, "Writing some data\n");
    
    if (fclose(file) != 0) {
        perror("Failed to close file");
        return 1;
    }

    return 0;
}