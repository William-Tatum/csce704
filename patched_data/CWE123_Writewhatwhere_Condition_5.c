#include <stdio.h>
#include <string.h>

void fixed_function(char *input) {
    char buffer[8];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';  // Ensure null-termination
}

int main(int argc, char **argv) {
    if (argc > 1) {
        fixed_function(argv[1]);
    }
    return 0;
}