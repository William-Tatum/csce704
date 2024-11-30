#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        return 1;
    }

    // Proper handling: Ensure each resource is released only once
    fclose(file);

    // Incorrect handling: Attempt to release the same resource again
    fclose(file);

    return 0;
}