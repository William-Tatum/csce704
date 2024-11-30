#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "This is a test.\n");
        fclose(file);  // Correct release

        // Incorrect: attempting to close the same resource again
        fclose(file);
    }
    return 0;
}