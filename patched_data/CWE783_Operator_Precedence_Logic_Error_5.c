#include <stdio.h>
#include <stdbool.h>

bool authenticate_user(int user_role, int required_role, bool has_permission) {
    return (user_role >= required_role && has_permission);
}

int main() {
    int user_role = 2;
    int required_role = 3;
    bool has_permission = false;

    if (authenticate_user(user_role, required_role, has_permission)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}