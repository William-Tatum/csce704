#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int secure_copy(const char *src, const char *dst) {
    int src_fd, dst_fd;
    char buffer[4096];
    ssize_t bytes_read, bytes_written;
    struct stat st;

    if (stat(src, &st) < 0) return -1;
    if (!S_ISREG(st.st_mode)) return -1;

    src_fd = open(src, O_RDONLY);
    if (src_fd < 0) return -1;

    dst_fd = open(dst, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP);
    if (dst_fd < 0) {
        if (errno == EEXIST) {
            close(src_fd);
            return -1;
        }
        fchown(dst_fd, getuid(), getgid());
        fchmod(dst_fd, S_IRUSR | S_IWUSR | S_IRGRP);
    }
    if (dst_fd < 0) {
        close(src_fd);
        return -1;
    }

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            close(src_fd);
            close(dst_fd);
            unlink(dst);
            return -1;
        }
    }
    
    if (bytes_read < 0) {
        close(src_fd);
        close(dst_fd);
        unlink(dst);
        return -1;
    }

    close(src_fd);
    close(dst_fd);
    
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return -1;
    }
    return secure_copy(argv[1], argv[2]);
}