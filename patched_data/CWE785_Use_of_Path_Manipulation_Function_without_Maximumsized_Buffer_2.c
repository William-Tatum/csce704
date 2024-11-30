#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int main() {
    const char *path = "/some/example/path/to/a/file";
    char resolved_path[PATH_MAX];
    
    if (realpath(path, resolved_path) == NULL) {
        perror("realpath error");
        return 1;
    }
    
    printf("Resolved path: %s\n", resolved_path);
    return 0;
}