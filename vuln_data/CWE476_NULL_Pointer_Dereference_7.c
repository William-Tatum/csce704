#include <stdio.h>

void printMessage(const char *message) {
    if (message == NULL) {
        printf("Error: NULL pointer dereference attempt detected.\n");
        return;
    }
    printf("%s\n", message);
}

int main() {
    const char *message = NULL;
    printMessage(message);
    return 0;
}