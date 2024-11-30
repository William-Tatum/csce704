#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void secureCopyFile(const char *source, const char *destination, mode_t mode) {
    int srcFd, destFd;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];
    struct stat statBuf;

    if (lstat(source, &statBuf) == -1) {
        perror("Error getting source file status");
        exit(EXIT_FAILURE);
    }

    if (S_ISLNK(statBuf.st_mode)) {
        fprintf(stderr, "Error: source file is a symbolic link\n");
        exit(EXIT_FAILURE);
    }

    srcFd = open(source, O_RDONLY);
    if (srcFd < 0) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    destFd = open(destination, O_WRONLY | O_CREAT | O_EXCL, mode);
    if (destFd < 0) {
        perror("Error creating destination file");
        close(srcFd);
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = read(srcFd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = 0;
        while (bytesWritten < bytesRead) {
            ssize_t result = write(destFd, buffer + bytesWritten, bytesRead - bytesWritten);
            if (result < 0) {
                if (errno == EINTR) continue;
                perror("Error writing to destination file");
                close(srcFd);
                close(destFd);
                exit(EXIT_FAILURE);
            }
            bytesWritten += result;
        }
    }

    if (bytesRead < 0) {
        perror("Error reading from source file");
    }

    if (close(srcFd) < 0) {
        perror("Error closing source file");
    }

    if (close(destFd) < 0) {
        perror("Error closing destination file");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    secureCopyFile(argv[1], argv[2], S_IRUSR | S_IWUSR);

    return 0;
}