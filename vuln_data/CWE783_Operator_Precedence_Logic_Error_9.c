#include <stdio.h>
#include <stdbool.h>

bool isAuthenticated(bool hasPassword, bool correctPassword, bool isAdmin) {
    return hasPassword && correctPassword || isAdmin;
}

int main() {
    bool hasPassword = true;
    bool correctPassword = false;
    bool isAdmin = false;

    if (isAuthenticated(hasPassword, correctPassword, isAdmin)) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }

    return 0;
}