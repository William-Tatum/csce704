#include <stdio.h>
#include <string.h>

volatile int securityCheck = 1;

int main() {
    char input[20];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);
    
    if (securityCheck == 1) {
        if (strncmp(input, "secret", 6) == 0) {
            printf("Access Granted.\n");
        } else {
            printf("Access Denied.\n");
        }
    } else {
        printf("Security check failed.\n");
    }

    return 0;
}