#include <stdio.h>
#include <string.h>

void printMessage(const char *message) {
    if (message == NULL) {
        printf("Error: NULL pointer provided.\n");
        return;
    }
    printf("%s\n", message);
}

int main() {
    const char *message = "Hello, world!";
    printMessage(message);
    return 0;
}