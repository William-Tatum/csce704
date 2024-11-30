#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        return 1;
    }
    
    close(fd);

    // Incorrectly using the closed file descriptor
    char buffer[10];
    if (read(fd, buffer, sizeof(buffer)) == -1) {
        return 1;
    }
    
    return 0;
}