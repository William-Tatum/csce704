#include <stdio.h>

void greetUser(const char *name) {
    printf("Hello, %s!\n", name);
}

int main() {
    const char *username = "Alice";
    greetUser(username);
    return 0;
}