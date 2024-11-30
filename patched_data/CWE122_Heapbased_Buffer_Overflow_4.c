#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln_function(char *input) {
    size_t length = strlen(input);
    if (length >= 20) {
        printf("Input too long!\n");
        return;
    }
    char *buffer = (char *)malloc(20);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(buffer, input, 19);
    buffer[19] = '\0';
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