#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void secure_copy(const char *src_file, const char *dst_file) {
    int src_fd = open(src_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (fstat(src_fd, &st) < 0) {
        perror("Failed to stat source file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    int dst_fd = open(dst_file, O_WRONLY | O_CREAT | O_EXCL, st.st_mode & (S_IRUSR | S_IWUSR));
    if (dst_fd < 0) {
        perror("Failed to open destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        char *ptr = buffer;
        while (bytes_read > 0) {
            bytes_written = write(dst_fd, ptr, bytes_read);
            if (bytes_written < 0) {
                perror("Failed to write to destination file");
                close(src_fd);
                close(dst_fd);
                exit(EXIT_FAILURE);
            }
            ptr += bytes_written;
            bytes_read -= bytes_written;
        }
    }

    if (bytes_read < 0) {
        perror("Failed to read from source file");
    }

    if (close(src_fd) < 0) {
        perror("Failed to close source file");
        close(dst_fd);
        exit(EXIT_FAILURE);
    }

    if (close(dst_fd) < 0) {
        perror("Failed to close destination file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    secure_copy(argv[1], argv[2]);
    return 0;
}