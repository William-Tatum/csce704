#include <stdio.h>

int main() {
    int isAuthenticated = 0;
    int adminRights = 0;
    int userInput = 1;

    if (userInput == 1 & isAuthenticated || adminRights) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}