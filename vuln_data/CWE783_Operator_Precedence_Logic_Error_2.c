#include <stdio.h>

int main() {
    int isAuthenticated = 0;
    int hasAdminAccess = 0;
    int inputUser = 1;
    int inputPass = 1234;

    if (inputUser == 1 && inputPass == 12345 || hasAdminAccess) {
        isAuthenticated = 1;
    }

    if (isAuthenticated) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }

    return 0;
}