#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t new_umask;
    mode_t file_mode;
    
    new_umask = 0755;
    umask(new_umask);

    file_mode = 0644;
    if (creat("example.txt", file_mode) < 0) {
        perror("creat");
        return 1;
    }

    return 0;
}