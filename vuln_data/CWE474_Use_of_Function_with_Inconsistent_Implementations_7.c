#include <stdio.h>
#include <stdlib.h>

int main() {
    char envVar[] = "PATH";
    char *pathValue;
    
    pathValue = getenv(envVar);
    if (pathValue != NULL) {
        printf("Current PATH: %s\n", pathValue);
    } else {
        printf("Unable to retrieve PATH environment variable.\n");
    }

    return 0;
}