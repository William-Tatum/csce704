#include <stdio.h>

void greet(const char *name) {
    if (name != NULL) {
        printf("Hello, %s!\n", name);
    } else {
        printf("Hello, guest!\n");
    }
}

int main() {
    greet("User");

    greet("Alice");

    return 0;
}