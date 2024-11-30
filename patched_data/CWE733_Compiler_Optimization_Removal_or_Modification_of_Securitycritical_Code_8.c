#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_password_correct(const char *input) {
    const char *password = "securepassword123";
    size_t input_len = strcspn(input, "\n"); // Get rid of newline if present
    return input_len == strlen(password) && strncmp(input, password, input_len) == 0;
}

int main() {
    char input[256];
    printf("Enter password: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    if (is_password_correct(input)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}