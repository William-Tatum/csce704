#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int copy_file(const char *source, const char *destination, mode_t file_mode) {
    int src_fd = open(source, O_RDONLY);
    if (src_fd < 0) return -1;

    int dst_fd = open(destination, O_WRONLY | O_CREAT | O_EXCL, file_mode | S_IRUSR | S_IWUSR);
    if (dst_fd < 0) {
        close(src_fd);
        return -1;
    }

    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        ssize_t bytes_written = 0;
        while (bytes_written < bytes_read) {
            ssize_t result = write(dst_fd, buffer + bytes_written, bytes_read - bytes_written);
            if (result < 0) {
                close(src_fd);
                close(dst_fd);
                return -1;
            }
            bytes_written += result;
        }
    }

    close(src_fd);
    close(dst_fd);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) return 1;

    char *end;
    errno = 0;
    mode_t mode = strtol(argv[3], &end, 8);
    if (errno != 0 || *end != '\0') {
        return 1;
    }

    if (copy_file(argv[1], argv[2], mode) < 0) {
        return 1;
    }

    return 0;
}