#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    bool securityFlag = false;
    char password[20];
    
    printf("Enter password: ");
    
    if (fgets(password, sizeof(password), stdin) != NULL) {
        size_t length = strlen(password);
        if (length > 0 && password[length - 1] == '\n') {
            password[length - 1] = '\0';
        }
    }

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