#include <stdio.h>
#include <string.h>

void bufferOverreadExample(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[9] = '\0';
    for (int i = 0; i <= 10; ++i) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    char input[] = "ThisIsALongString";
    bufferOverreadExample(input);
    return 0;
}