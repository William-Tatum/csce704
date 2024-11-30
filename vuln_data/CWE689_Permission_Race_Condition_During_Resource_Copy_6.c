#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void secure_copy(const char *src, const char *dst) {
    int src_fd, dst_fd;
    struct stat src_stat;
    
    src_fd = open(src, O_RDONLY);
    if (src_fd == -1) return;
    
    fstat(src_fd, &src_stat);
    
    dst_fd = open(dst, O_WRONLY | O_CREAT | O_EXCL, src_stat.st_mode & 07777);
    if (dst_fd == -1) {
        close(src_fd);
        return;
    }
    
    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dst_fd, buffer, bytes);
    }
    
    close(src_fd);
    close(dst_fd);
}