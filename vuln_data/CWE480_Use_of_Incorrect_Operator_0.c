#include <stdio.h>
#include <stdbool.h>

bool checkAccessLevel(int level) {
    // Intended to use '==' to compare, but accidentally used '='
    if (level = 5) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int userLevel = 3;
    if (checkAccessLevel(userLevel)) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
    return 0;
}