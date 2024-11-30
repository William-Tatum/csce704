#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int main() {
    char resolved_path[PATH_MAX];
    const char *path = "/usr/local/bin/somefile";
    
    if (realpath(path, resolved_path) == NULL) {
        perror("realpath failed");
        return EXIT_FAILURE;
    }
    
    printf("Resolved Path: %s\n", resolved_path);
    return EXIT_SUCCESS;
}