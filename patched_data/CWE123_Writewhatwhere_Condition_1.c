#include <stdio.h>
#include <string.h>

void safeFunction(char *input) {
    char buffer[64];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
}

int main() {
    char userData[128];
    printf("Enter your data: ");
    if (fgets(userData, sizeof(userData), stdin) != NULL) {
        userData[strcspn(userData, "\n")] = '\0';
        safeFunction(userData);
    }
    return 0;
}