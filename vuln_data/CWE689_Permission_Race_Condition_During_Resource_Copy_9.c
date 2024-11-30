#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

void secureCopyFile(const char *source, const char *destination, mode_t mode) {
    int srcFd, destFd;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];

    srcFd = open(source, O_RDONLY);
    if (srcFd < 0) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    destFd = open(destination, O_WRONLY | O_CREAT | O_EXCL, mode);
    if (destFd < 0) {
        perror("Error creating destination file with safe permissions");
        close(srcFd);
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = read(srcFd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(destFd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            close(srcFd);
            close(destFd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead < 0) {
        perror("Error reading from source file");
    }

    close(srcFd);
    close(destFd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    secureCopyFile(argv[1], argv[2], S_IRUSR | S_IWUSR);

    return 0;
}