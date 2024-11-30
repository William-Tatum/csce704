#include <stdio.h>
#include <string.h>

int main() {
    char password[] = "securepassword";
    char input[20];

    printf("Enter your password: ");
    scanf("%19s", input);

    if (strcmp(input, password) == 0) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}