#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int authenticate(char *password) {
    char *correct_password = "securepassword";
    return strcmp(password, correct_password) == 0;
}

int main() {
    char user_input[50];
    
    printf("Enter password: ");
    if (scanf("%49s", user_input) != 1) {
        printf("Error reading input\n");
        return 1;
    }
    
    if (authenticate(user_input)) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
    
    return 0;
}