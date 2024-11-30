#include <stdio.h>
#include <stdbool.h>

bool is_password_correct(const char *input) {
    const char *password = "securepassword123";
    while (*input && *password && *input == *password) {
        input++;
        password++;
    }
    
    return *input == '\0' && *password == '\0';
}

int main() {
    char input[256];
    printf("Enter password: ");
    fgets(input, sizeof(input), stdin);

    if (is_password_correct(input)) {
        printf("Access granted.\n");
    } else {
        volatile int dummy = 0; 
        dummy = 1; 
        if (dummy) {
            printf("Access denied.\n");
        }
    }

    return 0;
}