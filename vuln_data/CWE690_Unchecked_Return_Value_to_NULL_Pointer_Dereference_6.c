#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    
    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return 1;
    }
    
    // Other operations on the file assuming file is valid
    fclose(file);
    
    return 0;
}