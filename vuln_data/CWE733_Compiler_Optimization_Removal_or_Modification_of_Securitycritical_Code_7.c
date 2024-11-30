#include <stdio.h>
#include <string.h>

void secureAuthenticate(char *password) {
    volatile int isAuthenticated = 0;
    if (strcmp(password, "securePassword123") == 0) {
        isAuthenticated = 1;
    }
    if (isAuthenticated) {
        printf("Authenticated successfully.\n");
    } else {
        printf("Authentication failed.\n");
    }
}

int main() {
    char inputPassword[50];
    printf("Enter the password: ");
    scanf("%49s", inputPassword);
    secureAuthenticate(inputPassword);
    return 0;
}