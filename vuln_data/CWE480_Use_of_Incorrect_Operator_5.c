#include <stdio.h>
#include <stdbool.h>

int authenticate(char *password) {
    char *correct_password = "securepassword";
    return password == correct_password;
}

int main() {
    char *user_input = "securepassword";
    
    if (authenticate(user_input)) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
    
    return 0;
}