#include <stdio.h>

static int authorized_user = 0;

void authenticate_user() {
    // Secure authentication simulation using a fixed condition
    int user_input;
    printf("Enter password: ");
    scanf("%d", &user_input); // Vulnerable to format string, in production use secure password handling
    if (user_input == 1234) { // Example correct password (for demonstration purposes only)
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