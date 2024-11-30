#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_password(const char *input) {
    int authenticated = 0;
    if (strcmp(input, "correct_password") == 0) {
        authenticated = 1;
    }
    return authenticated;
}

int main() {
    char input[256];
    printf("Enter password: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;
        if (check_password(input)) {
            printf("Access Granted\n");
        } else {
            printf("Access Denied\n");
        }
    } else {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}