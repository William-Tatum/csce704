#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

void secure_copy(const char *source_path, const char *dest_path) {
    int source_fd, dest_fd;
    struct stat st;
    mode_t old_mask;

    source_fd = open(source_path, O_RDONLY);
    if (source_fd < 0) {
        perror("Failed to open source file");
        exit(1);
    }

    if (fstat(source_fd, &st) != 0) {
        perror("Failed to get source file stat");
        close(source_fd);
        exit(1);
    }

    old_mask = umask(077);
    dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_EXCL, 0600);
    umask(old_mask);

    if (dest_fd < 0) {
        perror("Failed to open destination file");
        close(source_fd);
        exit(1);
    }

    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        ssize_t bytes_written = 0;
        ssize_t result;
        while (bytes_written < bytes_read) {
            result = write(dest_fd, buffer + bytes_written, bytes_read - bytes_written);
            if (result < 0) {
                perror("Failed to write to destination file");
                close(source_fd);
                close(dest_fd);
                exit(1);
            }
            bytes_written += result;
        }
    }

    if (bytes_read < 0) {
        perror("Failed to read from source file");
    }

    if (fchmod(dest_fd, st.st_mode & 07777) != 0) {
        perror("Failed to set destination file permissions");
    }

    close(source_fd);
    close(dest_fd);
}