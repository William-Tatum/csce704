#include <stdio.h>

void printBuffer(char *buffer, int length) {
    for (int i = 0; i <= length; i++) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    char buffer[10] = "Hello";
    printBuffer(buffer, 10);
    return 0;
}