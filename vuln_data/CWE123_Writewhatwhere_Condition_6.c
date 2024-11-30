#include <string.h>
#include <stdio.h>

void vulnerableFunction(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        vulnerableFunction(argv[1]);
    }
    return 0;
}