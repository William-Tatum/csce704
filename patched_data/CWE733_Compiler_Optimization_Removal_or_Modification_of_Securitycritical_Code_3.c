#include <stdio.h>
#include <string.h>

void security_check(const char *input) {
    int authorized = 0; 
    if (strncmp(input, "correct_password", 15) == 0) {
        authorized = 1;
    }
    
    if (authorized) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }
}

int main() {
    char user_input[20];
    printf("Enter password: ");
    if (scanf("%19s", user_input) != 1) {
        printf("Input error.\n");
        return 1;
    }
    security_check(user_input);
    return 0;
}