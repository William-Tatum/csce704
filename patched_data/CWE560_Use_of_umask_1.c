#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    umask(0022);
    FILE *file = fopen("example.txt", "w");
    if (file != NULL) {
        fputs("This is an example file.", file);
        fclose(file);
    }
    return 0;
}