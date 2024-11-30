#include <stdio.h>

void printMessage(char *message) {
    if (message == NULL) {
        printf("Error: message is NULL\n");
        return;
    }
    printf("%s\n", message);
}

int main() {
    char *msg = NULL;
    printMessage(msg);
    return 0;
}