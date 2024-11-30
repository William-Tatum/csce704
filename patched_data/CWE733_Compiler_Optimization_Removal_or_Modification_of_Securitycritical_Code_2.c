#include <stdio.h>
#include <string.h>

volatile int authenticate = 0;

void check_password(const char *input) {
    const char *password = "securepassword";
    if (strncmp(input, password, strlen(password) + 1) == 0) {
        authenticate = 1;
    } else {
        authenticate = 0;
    }
}

int main() {
    char input[20];
    printf("Enter password: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;
        check_password(input);
    }
    
    if (authenticate) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
    
    return 0;
}