#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file;
    int fd;

    file = fopen("example.txt", "w");
    if (file == NULL) {
        return 1;
    }

    fd = fileno(file);
    fprintf(file, "Writing initial data.\n");
    fclose(file);

    dprintf(fd, "Writing to closed file descriptor.\n"); // CWE-910 - Use of expired file descriptor

    return 0;
}