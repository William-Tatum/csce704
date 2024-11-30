#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    mode_t correctMask = 0022;
    umask(correctMask);
    int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        return 1;
    }
    write(fd, "Hello, world!\n", 14);
    close(fd);
    return 0;
}