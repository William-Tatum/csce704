#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        return 1;
    }
    if (write(fd, "This is a test.", 15) == -1) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}