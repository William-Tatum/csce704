#include <stdio.h>
#include <string.h>

void secure_function(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        secure_function(argv[1]);
    }
    return 0;
}