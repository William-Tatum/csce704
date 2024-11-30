#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t old_mask;
    old_mask = umask(0);
    printf("Old umask: %04o\n", old_mask);
    umask(S_IRWXO | S_IRWXG); // Example secure umask
    return 0;
}