#include <unistd.h>
#include <stdio.h>

int main() {
    if (chroot("/newroot") != 0) {
        perror("chroot failed");
        return 1;
    }

    if (chdir("/") != 0) {
        perror("chdir failed");
        return 1;
    }

    // Now the process is properly contained within the chroot jail

    return 0;
}