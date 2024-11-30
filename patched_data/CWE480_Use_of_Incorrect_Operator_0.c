#include <stdio.h>
#include <stdbool.h>

bool checkAccessLevel(int level) {
    if (level == 5) {
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