#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void copy_file_secure(const char *source, const char *destination, mode_t permissions) {
    int src_fd = open(source, O_RDONLY);
    if (src_fd == -1) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    int dst_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, permissions);
    if (dst_fd == -1) {
        perror("Failed to open destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Write error");
            close(src_fd);
            close(dst_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Read error");
    }

    if (fchmod(dst_fd, permissions) == -1) {
        perror("Failed to set file permissions");
    }

    close(src_fd);
    close(dst_fd);
}

int main() {
    const char *source = "source.txt";
    const char *destination = "destination.txt";
    mode_t permissions = 0600;
    copy_file_secure(source, destination, permissions);
    return 0;
}