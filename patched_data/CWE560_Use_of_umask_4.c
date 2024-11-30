#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t prev_umask = umask(022);  // Correct umask to allow owner full access
    FILE *file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "This is a test file.\n");
        fclose(file);
    }
    umask(prev_umask);  // Restore previous umask
    return 0;
}