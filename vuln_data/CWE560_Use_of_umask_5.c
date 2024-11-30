#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    mode_t wrongMask = 0644;
    umask(wrongMask);
    int fd = open("file.txt", O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
        return 1;
    }
    write(fd, "Hello, world!\n", 14);
    close(fd);
    return 0;
}