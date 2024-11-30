#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void secureAuthenticate(const char *password) {
    bool isAuthenticated = false;
    if (strncmp(password, "securePassword123", 50) == 0) {
        isAuthenticated = true;
    }
    if (isAuthenticated) {
        printf("Authenticated successfully.\n");
    } else {
        printf("Authentication failed.\n");
    }
}

int main() {
    char inputPassword[51];
    printf("Enter the password: ");
    if (fgets(inputPassword, sizeof(inputPassword), stdin) != NULL) {
        size_t len = strlen(inputPassword);
        if (len > 0 && inputPassword[len - 1] == '\n') {
            inputPassword[len - 1] = '\0';
        }
    }
    secureAuthenticate(inputPassword);
    return 0;
}