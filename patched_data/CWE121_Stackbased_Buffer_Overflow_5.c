#include <stdio.h>
#include <string.h>

void safe_function(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        safe_function(argv[1]);
    } else {
        printf("Usage: %s <string>\n", argv[0]);
    }
    return 0;
}