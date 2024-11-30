#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) return 1;
    close(fd);
    write(fd, "This might not be written to the intended file\n", 47);
    return 0;
}