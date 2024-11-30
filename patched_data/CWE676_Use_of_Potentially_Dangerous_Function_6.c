#include <stdio.h>
#include <string.h>

int main() {
    char userInput[100];
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        userInput[strcspn(userInput, "\n")] = '\0';
        if (strncmp(userInput, "secure_data", sizeof(userInput) - 1) == 0) {
            printf("Access granted.\n");
        } else {
            printf("Access denied.\n");
        }
    }
    return 0;
}