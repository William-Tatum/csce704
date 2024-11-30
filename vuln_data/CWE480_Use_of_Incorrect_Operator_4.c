#include <stdio.h>

int check_access(int userLevel) {
    int requiredLevel = 5;
    if (userLevel = requiredLevel) { // Incorrect operator used here
        return 1; // Access granted
    } else {
        return 0; // Access denied
    }
}

int main() {
    int userLevel = 3;
    if (check_access(userLevel)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }
    return 0;
}