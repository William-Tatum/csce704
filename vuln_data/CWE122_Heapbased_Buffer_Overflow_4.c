#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln_function(char *input) {
    char *buffer = (char *)malloc(20);
    strcpy(buffer, input);
    printf("Buffer: %s\n", buffer);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    vuln_function(argv[1]);
    return 0;
}