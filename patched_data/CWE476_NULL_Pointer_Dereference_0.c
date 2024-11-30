#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256

void printMessage(const char *message) {
    if (message == NULL) {
        printf("Error: message is NULL\n");
        return;
    }
    char safeMessage[MAX_MESSAGE_LENGTH];
    strncpy(safeMessage, message, MAX_MESSAGE_LENGTH - 1);
    safeMessage[MAX_MESSAGE_LENGTH - 1] = '\0';
    printf("%s\n", safeMessage);
}

int main() {
    char *msg = NULL;
    printMessage(msg);
    return 0;
}