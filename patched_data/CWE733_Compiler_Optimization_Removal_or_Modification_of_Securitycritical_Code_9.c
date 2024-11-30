#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_function(int check_password) {
    if (check_password) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }
}

int main() {
    char password[21];
    int check_password = 0;
    printf("Enter password: ");
    if (fgets(password, sizeof(password), stdin) != NULL) {
        password[strcspn(password, "\n")] = '\0';  // Remove newline character if present
        if (strcmp(password, "secret") == 0) {
            check_password = 1;
        }
    }

    secure_function(check_password);
    return 0;
}