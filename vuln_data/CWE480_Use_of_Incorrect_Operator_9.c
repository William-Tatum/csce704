#include <stdio.h>
#include <stdbool.h>

bool isAuthorizedUser() {
    // Dummy check for user's authorization
    return true;
}

int main() {
    bool userAuthorized = isAuthorizedUser();

    if (userAuthorized = false) {
        printf("User is not authorized.\n");
    } else {
        printf("User is authorized.\n");
    }

    return 0;
}