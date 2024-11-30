#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int copy_file(const char *source, const char *destination, mode_t file_mode) {
    int src_fd = open(source, O_RDONLY);
    if (src_fd < 0) return -1;

    int dst_fd = open(destination, O_WRONLY | O_CREAT | O_EXCL, file_mode);
    if (dst_fd < 0) {
        close(src_fd);
        return -1;
    }

    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dst_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dst_fd);

    struct stat dst_stat;
    if ((stat(destination, &dst_stat) == 0) && (dst_stat.st_mode & 0777) != file_mode) {
        chmod(destination, file_mode);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) return 1;

    mode_t mode = strtol(argv[3], NULL, 8);
    if (copy_file(argv[1], argv[2], mode) < 0) {
        return 1;
    }

    return 0;
}