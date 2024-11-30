#include <stdio.h>

void displayMessage(const char *message, int repeatCount) {
    if (repeatCount < 0) {
        fprintf(stderr, "Invalid repeat count\n");
        return;
    }
    for (int i = 0; i < repeatCount; i++) {
        printf("%s\n", message);
    }
}

int main() {
    displayMessage("Hello, World!", 1);
    return 0;
}