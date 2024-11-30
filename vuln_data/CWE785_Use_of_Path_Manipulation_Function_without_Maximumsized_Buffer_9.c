#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char resolved_path[100];
    const char *path = "/usr/local/bin/somefile";
    
    if (realpath(path, resolved_path) == NULL) {
        perror("realpath failed");
        return EXIT_FAILURE;
    }
    
    printf("Resolved Path: %s\n", resolved_path);
    return EXIT_SUCCESS;
}