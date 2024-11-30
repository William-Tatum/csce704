#include <stdio.h>
#include <stdbool.h>

bool authenticate_user(bool is_admin, bool password_correct) {
    return is_admin && password_correct;
}

int main() {
    bool is_admin = false;
    bool password_correct = true;
    
    if (authenticate_user(is_admin, password_correct)) {
        printf("User authenticated.\n");
    } else {
        printf("Authentication failed.\n");
    }
    
    return 0;
}