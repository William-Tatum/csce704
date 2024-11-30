#include <stdio.h>

void displayMessage(const char *message) {
    printf("%s\n", message);
}

int main() {
    int importantValue = 42;
    displayMessage(importantValue);
    return 0;
}