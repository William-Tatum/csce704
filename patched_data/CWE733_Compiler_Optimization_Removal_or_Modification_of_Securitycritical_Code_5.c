#include <stdio.h>
#include <string.h>

volatile int securityCheck = 1;

int main() {
    char input[20];
    printf("Enter your input: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if (securityCheck == 1) {
            if (strncmp(input, "secret", 6) == 0 && strlen(input) == 6) {
                printf("Access Granted.\n");
            } else {
                printf("Access Denied.\n");
            }
        } else {
            printf("Security check failed.\n");
        }
    }

    return 0;
}