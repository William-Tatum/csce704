#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        return 1;
    }

    fprintf(file, "Sample text.\n");

    fclose(file);

    // Incorrect: Attempting to close the same handle again
    fclose(file);

    return 0;
}