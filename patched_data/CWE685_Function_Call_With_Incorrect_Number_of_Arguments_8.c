#include <stdio.h>

void printMessage(const char* message);

int main() {
    printMessage("Hello, World!");
    return 0;
}

void printMessage(const char* message) {
    printf("%s\n", message);
}