#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file;
    
    file = fopen("example.txt", "w");
    if (file == NULL) {
        return 1;
    }

    fprintf(file, "Writing initial data.\n");
    fclose(file);

    return 0;
}