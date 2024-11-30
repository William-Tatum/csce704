#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "This is a test.\n");
        fclose(file);
        file = NULL; // Set pointer to NULL after closing
    }
    return 0;
}