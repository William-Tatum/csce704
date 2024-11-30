#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t new_umask;
    new_umask = umask(0022);

    printf("Previous umask: %03o\n", new_umask);
    
    return 0;
}