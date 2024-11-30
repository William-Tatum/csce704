#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int filedesc = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (filedesc < 0) {
        return 1;
    }

    close(filedesc);

    if (write(filedesc, "Hello, World!", 13) < 0) {
        perror("write");
        return 1;
    }

    return 0;
}