#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    umask(0);

    if (creat("example.txt", 0644) < 0) {
        perror("File creation failed");
        return 1;
    }

    return 0;
}