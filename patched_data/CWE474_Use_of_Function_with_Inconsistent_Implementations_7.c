#include <stdio.h>
#include <stdlib.h>

int main() {
    char envVar[] = "PATH";
    char *pathValue;
    
    pathValue = getenv(envVar);
    if (pathValue != NULL) {
        // limit the output to a reasonable length to prevent excessive printing
        printf("Current PATH: %.1024s\n", pathValue);
    } else {
        fprintf(stderr, "Unable to retrieve PATH environment variable.\n");
    }

    return 0;
}