#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

void secure_copy(const char *src, const char *dst) {
    int src_fd, dst_fd;
    struct stat src_stat, dst_stat;
    char real_src[PATH_MAX], real_dst[PATH_MAX];

    if (realpath(src, real_src) == NULL) return;
    if (realpath(dst, real_dst) == NULL) return;

    if (strcmp(real_src, real_dst) == 0) return;

    if (stat(src, &src_stat) == -1) return;
    if (!S_ISREG(src_stat.st_mode)) return;

    src_fd = open(src, O_RDONLY);
    if (src_fd == -1) return;

    if (fstat(src_fd, &src_stat) == -1) {
        close(src_fd);
        return;
    }

    dst_fd = open(dst, O_WRONLY | O_CREAT | O_EXCL, src_stat.st_mode & 0700);
    if (dst_fd == -1) {
        close(src_fd);
        return;
    }

    if (fstat(dst_fd, &dst_stat) == -1 || dst_stat.st_ino == src_stat.st_ino) {
        close(src_fd);
        close(dst_fd);
        return;
    }

    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dst_fd, buffer, bytes) != bytes) {
            close(src_fd);
            close(dst_fd);
            return;
        }
    }

    close(src_fd);
    close(dst_fd);
}