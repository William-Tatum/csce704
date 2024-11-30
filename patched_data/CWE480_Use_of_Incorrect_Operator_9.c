#include <stdio.h>
#include <stdbool.h>

bool isAuthorizedUser() {
    return true;
}

int main() {
    bool userAuthorized = isAuthorizedUser();

    if (userAuthorized == false) {
        printf("User is not authorized.\n");
    } else {
        printf("User is authorized.\n");
    }

    return 0;
}