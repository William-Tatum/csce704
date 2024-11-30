#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int filedesc = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (filedesc < 0) {
        perror("open");
        return 1;
    }

    if (write(filedesc, "Hello, World!", 13) < 0) {
        perror("write");
        close(filedesc);
        return 1;
    }

    if (close(filedesc) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}