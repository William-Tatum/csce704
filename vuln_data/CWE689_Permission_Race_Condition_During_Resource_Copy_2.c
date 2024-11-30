#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int copy_file_secure(const char *src, const char *dst, mode_t mode) {
    int src_fd = open(src, O_RDONLY);
    if (src_fd == -1) return -1;

    int dst_fd = open(dst, O_WRONLY | O_CREAT | O_EXCL, mode);
    if (dst_fd == -1) {
        close(src_fd);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    while ((bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dst_fd, buffer, bytes) != bytes) {
            close(src_fd);
            close(dst_fd);
            return -1;
        }
    }

    close(src_fd);
    close(dst_fd);
    return 0;
}

int main() {
    const char *source = "source.txt";
    const char *destination = "destination.txt";
    mode_t file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    if (copy_file_secure(source, destination, file_mode) == 0) {
        printf("File copied securely.\n");
    } else {
        printf("Failed to copy file securely.\n");
    }

    return 0;
}