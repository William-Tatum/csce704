#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void safe_copy(const char *source, const char *destination, mode_t mode) {
    struct stat src_stat;
    if (stat(source, &src_stat) < 0) return;

    int src_file = open(source, O_RDONLY);
    if (src_file < 0) return;

    int dest_file = open(destination, O_WRONLY | O_CREAT | O_TRUNC | O_EXCL, mode);
    if (dest_file < 0) {
        close(src_file);
        return;
    }

    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(src_file, buffer, sizeof(buffer))) > 0) {
        if (write(dest_file, buffer, bytes) != bytes) {
            close(src_file);
            close(dest_file);
            unlink(destination);
            return;
        }
    }

    struct stat dest_stat;
    if (fstat(dest_file, &dest_stat) < 0 || dest_stat.st_uid != getuid() || dest_stat.st_mode & (S_IWGRP | S_IWOTH)) {
        close(src_file);
        close(dest_file);
        unlink(destination);
        return;
    }

    close(src_file);
    close(dest_file);
}

int main() {
    const char *source = "source.txt";
    const char *destination = "destination.txt";
    mode_t mode = S_IRUSR | S_IWUSR;

    safe_copy(source, destination, mode);
    return 0;
}