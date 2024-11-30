#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    mode_t file_mode;
    
    file_mode = 0644;
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_EXCL, file_mode);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    close(fd);

    return 0;
}