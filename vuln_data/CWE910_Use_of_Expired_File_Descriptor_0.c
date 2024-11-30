#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        return 1;
    }

    close(fd);

    if (write(fd, "Hello, World!", 13) == -1) {
        return 2;
    }

    return 0;
}