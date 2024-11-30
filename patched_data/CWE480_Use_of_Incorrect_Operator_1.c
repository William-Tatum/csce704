#include <stdio.h>
#include <string.h>

int checkPassword(const char *input) {
    const char *correctPassword = "secure123";
    if (strcmp(input, correctPassword) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[20];
    printf("Enter password: ");
    if (scanf("%19s", password) != 1) {
        printf("Input error.\n");
        return 1;
    }
    if (checkPassword(password)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }
    return 0;
}