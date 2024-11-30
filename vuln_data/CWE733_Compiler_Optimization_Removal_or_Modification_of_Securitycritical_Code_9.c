#include <stdio.h>
#include <stdlib.h>

volatile int check_password = 1;

void secure_function() {
    if (check_password) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }
}

int main() {
    char password[20];
    printf("Enter password: ");
    fgets(password, 20, stdin);

    if (strncmp(password, "secret", 6) == 0) {
        check_password = 1;
    } else {
        check_password = 0;
    }

    secure_function();
    return 0;
}