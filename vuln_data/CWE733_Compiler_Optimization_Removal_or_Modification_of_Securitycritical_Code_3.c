#include <stdio.h>
#include <string.h>

void security_check(char *input) {
    volatile int authorized = 0; 
    if (strcmp(input, "correct_password") == 0) {
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
    scanf("%19s", user_input);
    security_check(user_input);
    return 0;
}