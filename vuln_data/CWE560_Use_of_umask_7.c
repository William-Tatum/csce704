#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    // Incorrect umask value used as if it is a chmod argument
    umask(0644);

    FILE *file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "This is a test file.\n");
        fclose(file);
    } else {
        perror("Failed to open file");
    }

    return 0;
}