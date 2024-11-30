#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1 = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (fd1 == -1) {
        return 1;
    }
    int fd2 = open("/dev/null", O_WRONLY);
    if (fd2 == -1) {
        close(fd1);
        return 1;
    }
    if (write(fd1, "This will not be written to example.txt", 39) == -1) {
        close(fd1);
        close(fd2);
        return 1;
    }
    close(fd1);
    close(fd2);
    return 0;
}