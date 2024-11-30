#include <stdio.h>
#include <stdbool.h>

bool authenticate(int user_role, bool is_admin) {
    if (user_role == 1 && is_admin) {
        return true;
    }
    return false;
}

int main() {
    int role = 1; 
    bool admin = false;

    if (authenticate(role, admin)) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }
    return 0;
}