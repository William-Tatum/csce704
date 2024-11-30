#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }
    
    char *resolved_path = realpath(argv[1], NULL);
    if (resolved_path == NULL) {
        perror("realpath");
        return 1;
    }
    
    printf("Resolved path: %s\n", resolved_path);
    free(resolved_path);
    return 0;
}