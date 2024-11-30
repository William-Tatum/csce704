#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void safe_copy(const char *source, const char *destination, mode_t mode) {
    int src_file = open(source, O_RDONLY);
    if (src_file < 0) return;

    int dest_file = open(destination, O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (dest_file < 0) {
        close(src_file);
        return;
    }

    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(src_file, buffer, sizeof(buffer))) > 0) {
        if (write(dest_file, buffer, bytes) != bytes) {
            close(src_file);
            close(dest_file);
            return;
        }
    }

    if (fchmod(dest_file, mode) < 0) {
        close(src_file);
        close(dest_file);
        return;
    }

    close(src_file);
    close(dest_file);
}

int main() {
    const char *source = "source.txt";
    const char *destination = "destination.txt";
    mode_t mode = S_IRUSR | S_IWUSR;

    safe_copy(source, destination, mode);
    return 0;
}