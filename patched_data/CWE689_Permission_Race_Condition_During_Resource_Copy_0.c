#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void copy_file_with_proper_permissions(const char *src, const char *dest, mode_t mode) {
    int src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }
    
    int dest_fd = open(dest, O_WRONLY | O_CREAT | O_EXCL, mode);
    if (dest_fd < 0) {
        perror("Error creating destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        ssize_t bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read < 0) {
        perror("Error reading from source file");
        close(src_fd);
        close(dest_fd);
        exit(EXIT_FAILURE);
    }

    if (close(src_fd) < 0) {
        perror("Error closing source file");
    }
    if (close(dest_fd) < 0) {
        perror("Error closing destination file");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    struct stat st;
    if (stat(argv[1], &st) != 0) {
        perror("Error getting source file permissions");
        exit(EXIT_FAILURE);
    }
    
    umask(0);
    copy_file_with_proper_permissions(argv[1], argv[2], st.st_mode & 0700);

    return 0;
}