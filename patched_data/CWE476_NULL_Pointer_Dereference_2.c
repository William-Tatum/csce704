#include <stdio.h>
#include <stdlib.h>

void printMessage(const char *message) {
    if (message != NULL) {
        printf("%s\n", message);
    } else {
        fprintf(stderr, "Error: Null pointer received.\n");
    }
}

int main() {
    const char *text = "Default message";
    printMessage(text);
    return 0;
}