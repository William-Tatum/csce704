#include <stdio.h>
#include <stdbool.h>

bool condition = false;

void security_check() {
    if (condition) {
        printf("Security check passed.\n");
    } else {
        printf("Security breach!\n");
    }
}

int main() {
    security_check();
    return 0;
}