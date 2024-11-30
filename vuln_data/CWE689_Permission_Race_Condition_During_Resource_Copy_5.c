#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void secure_copy(const char *source_path, const char *dest_path) {
    int source_fd, dest_fd;
    struct stat st;
    mode_t old_mask;

    source_fd = open(source_path, O_RDONLY);
    if (source_fd < 0) exit(1);

    fstat(source_fd, &st);

    old_mask = umask(077);
    dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_EXCL, 0600);
    umask(old_mask);

    if (dest_fd < 0) {
        close(source_fd);
        exit(1);
    }

    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dest_fd, buffer, bytes_read) != bytes_read) {
            close(source_fd);
            close(dest_fd);
            exit(1);
        }
    }

    fchmod(dest_fd, st.st_mode);

    close(source_fd);
    close(dest_fd);
}