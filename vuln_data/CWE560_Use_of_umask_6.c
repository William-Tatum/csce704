#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // Incorrect use of umask, thinking it's a chmod argument
    mode_t incorrect_mask = 0644;
    umask(incorrect_mask);

    if (creat("example.txt", 0666) < 0) {
        perror("File creation failed");
        return 1;
    }

    return 0;
}