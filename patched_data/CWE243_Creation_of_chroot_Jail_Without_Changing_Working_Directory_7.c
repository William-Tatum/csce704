#include <unistd.h>
#include <stdlib.h>

int main() {
    if (chdir("/path/to/jail") != 0) {
        return 1;
    }
    if (chroot(".") != 0) {
        return 1;
    }
    if (chdir("/") != 0) {
        return 1;
    }
    if (setuid(getuid()) != 0) {
        return 1;
    }
    return 0;
}