#include <stdio.h>
#include <stdlib.h>

int check_password(const char *input) {
    volatile int authenticated = 0;
    if (strcmp(input, "correct_password") == 0) {
        authenticated = 1;
    }
    return authenticated;
}

int main() {
    char input[256];
    printf("Enter password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (check_password(input)) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
    return 0;
}