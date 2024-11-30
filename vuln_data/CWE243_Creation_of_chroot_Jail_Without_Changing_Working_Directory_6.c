#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    const char *new_root = "/path/to/jail";
    
    if (chroot(new_root) != 0) {
        perror("chroot");
        exit(EXIT_FAILURE);
    }
    
    if (chdir("/") != 0) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }
    
    /* The process is now in a chroot jail and working directory is set */
    
    return 0;
}