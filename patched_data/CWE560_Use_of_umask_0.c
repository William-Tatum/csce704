#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t mask = 0022;
    umask(mask);

    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    fprintf(file, "Hello, World!\n");
    if (fclose(file) != 0) {
        perror("Failed to close file");
        return 1;
    }

    return 0;
}