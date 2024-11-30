#include <stdio.h>
#include <stdbool.h>

int authenticateUser(bool isAdmin, bool hasAccessKey) {
    if (isAdmin && hasAccessKey) {
        return 1; // Authentication successful
    }
    return 0; // Authentication failed
}

int main() {
    bool isAdmin = false;
    bool hasAccessKey = true;

    if (authenticateUser(isAdmin, hasAccessKey)) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }

    return 0;
}