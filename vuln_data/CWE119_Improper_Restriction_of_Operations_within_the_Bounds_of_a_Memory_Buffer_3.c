#include <stdio.h>

void vulnerableFunction(const char *input) {
    char buffer[10];
    for (int i = 0; input[i] != '\0'; ++i) {
        buffer[i] = input[i];
    }
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char *largeString = "This input string is definitely too large for the buffer";
    vulnerableFunction(largeString);
    return 0;
}