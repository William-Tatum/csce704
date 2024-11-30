#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t mask = 0644;
    umask(mask);

    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    fprintf(file, "Hello, World!\n");
    fclose(file);

    return 0;
}