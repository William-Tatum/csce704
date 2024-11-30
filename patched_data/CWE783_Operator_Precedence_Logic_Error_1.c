#include <stdio.h>
#include <stdbool.h>

bool isValidUser(bool isAdmin, bool isVerified, bool hasAccess) {
    return (isAdmin && isVerified) || hasAccess;
}

int main() {
    bool isAdmin = false;
    bool isVerified = true;
    bool hasAccess = false;

    if (isValidUser(isAdmin, isVerified, hasAccess)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}