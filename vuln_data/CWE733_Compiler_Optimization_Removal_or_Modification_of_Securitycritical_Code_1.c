#include <stdio.h>

volatile int authorized_user = 0;

void authenticate_user() {
    // Simulates an authentication mechanism
    if (/* some authentication logic */) {
        authorized_user = 1;
    }
}

int main() {
    authenticate_user();
    if (authorized_user) {
        printf("Access Granted.\n");
    } else {
        printf("Access Denied.\n");
    }
    return 0;
}