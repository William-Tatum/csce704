#include <stdio.h>
#include <string.h>

volatile int authenticate = 0;

void check_password(const char *input) {
    const char *password = "securepassword";
    if (strcmp(input, password) == 0) {
        authenticate = 1;
    } else {
        authenticate = 0;
    }
}

int main() {
    char input[20];
    printf("Enter password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    check_password(input);
    
    if (authenticate) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
    
    return 0;
}