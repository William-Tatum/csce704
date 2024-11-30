#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        return 1;
    }
    
    // Writing to the file
    fprintf(file, "This is an example text.\n");

    // Closing the file only once
    fclose(file);

    return 0;
}