#include <stdio.h>

void printMessage(const char *message) {
    printf("%s\n", message);
}

int main() {
    printMessage("Hello, World!", "Extra argument");
    return 0;
}