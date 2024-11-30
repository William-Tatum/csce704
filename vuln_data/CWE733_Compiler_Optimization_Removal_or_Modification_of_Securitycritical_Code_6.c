#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    bool securityFlag = false;
    char password[20];

    printf("Enter password: ");
    scanf("%19s", password);

    if (strcmp(password, "securePassword123") == 0) {
        securityFlag = true;
    }

    if (securityFlag) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}