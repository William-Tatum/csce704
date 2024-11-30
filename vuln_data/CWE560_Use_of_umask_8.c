#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t old_mask;
    /* Incorrect umask: treating it as if it's a chmod argument */
    old_mask = umask(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    printf("Old umask: %04o\n", old_mask);
    return 0;
}