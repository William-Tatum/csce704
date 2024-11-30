#include <stdio.h>

void displayMessage(const char *message) {
    printf("%s\n", message);
}

int main() {
    int importantValue = 42;
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "The important value is: %d", importantValue);
    displayMessage(buffer);
    return 0;
}