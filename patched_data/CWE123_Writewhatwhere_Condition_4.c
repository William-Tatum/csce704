#include <stdio.h>
#include <string.h>

void safe(char *input) {
    char buffer[10];
    if (strlen(input) >= sizeof(buffer)) {
        printf("Input is too long!\n");
        return;
    }
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        safe(argv[1]);
    } else {
        printf("Please provide an input.\n");
    }
    return 0;
}