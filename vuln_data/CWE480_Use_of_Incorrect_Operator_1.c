#include <stdio.h>

int checkPassword(char *input) {
    char *correctPassword = "secure123";
    if (input = correctPassword) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[20];
    printf("Enter password: ");
    scanf("%19s", password);
    if (checkPassword(password)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }
    return 0;
}