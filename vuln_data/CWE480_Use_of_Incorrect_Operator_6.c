#include <stdio.h>

int authenticate(int user_input) {
    int correct_password = 12345;
    if (user_input = correct_password) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int user_input;
    printf("Enter password: ");
    scanf("%d", &user_input);

    if (authenticate(user_input)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}