#include <string.h>
#include <stdio.h>

void safeFunction(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        safeFunction(argv[1]);
    }
    return 0;
}