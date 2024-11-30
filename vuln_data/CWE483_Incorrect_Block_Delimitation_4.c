#include <stdio.h>

void check_permission(int user_role) {
    if (user_role == 1)
        printf("Access granted.\n");
        printf("Welcome, Admin!\n");  // This line is not within the intended block
}

int main() {
    int user_role = 1;
    check_permission(user_role);
    return 0;
}