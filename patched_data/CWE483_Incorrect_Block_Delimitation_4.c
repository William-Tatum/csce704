#include <stdio.h>

void check_permission(int user_role) {
    if (user_role == 1) {
        printf("Access granted.\n");
        printf("Welcome, Admin!\n");
    }
}

int main() {
    int user_role = 1;
    check_permission(user_role);
    return 0;
}