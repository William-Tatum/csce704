#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        return 1;
    }
    
    char buffer[10];
    if (read(fd, buffer, sizeof(buffer)) == -1) {
        close(fd);
        return 1;
    }
    
    close(fd);
    return 0;
}