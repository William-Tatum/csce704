#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t new_umask = 022; // Correct umask
    mode_t old_umask = umask(new_umask);

    printf("Old umask: %03o\n", old_umask);
    printf("New umask set to: %03o\n", new_umask);

    return 0;
}