#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        return 1;
    }
    // ... Do something with the file

    fclose(file);

    // Incorrectly attempt to close the file again
    fclose(file);

    return 0;
}