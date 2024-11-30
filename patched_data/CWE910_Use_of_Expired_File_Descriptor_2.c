#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) return 1;
    if (write(fd, "This will be written to the intended file\n", 43) == -1) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}