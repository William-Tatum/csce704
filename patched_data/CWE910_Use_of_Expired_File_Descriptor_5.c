#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        return 1;
    }

    if (read(fd, buffer, sizeof(buffer) - 1) == -1) {
        close(fd);
        return 1;
    }

    buffer[sizeof(buffer) - 1] = '\0';

    close(fd);

    return 0;
}