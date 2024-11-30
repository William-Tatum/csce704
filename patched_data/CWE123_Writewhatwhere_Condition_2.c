#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_function(char *input) {
    char buffer[64];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    secure_function(argv[1]);
    return 0;
}