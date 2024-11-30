#include <stdio.h>

void displayMessage(const char *message, int repeatCount) {
    for (int i = 0; i < repeatCount; i++) {
        printf("%s\n", message);
    }
}

int main() {
    displayMessage("Hello, World!");
    return 0;
}