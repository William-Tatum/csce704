#include <unistd.h>

int main() {
    if (chroot("/path/to/jail") != 0) {
        return 1;
    }
    if (chdir("/") != 0) {
        return 1;
    }
    // Continue with execution within the chroot jail
    return 0;
}