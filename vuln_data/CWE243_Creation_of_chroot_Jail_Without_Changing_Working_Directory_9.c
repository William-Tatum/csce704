#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (chroot("/var/jail") != 0) {
        perror("chroot failed");
        exit(1);
    }
    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(1);
    }
    
    // The process is now in a secure chroot jail with the working directory changed.
    
    // Application logic here
    
    return 0;
}