#include <stdio.h>

void greetUser(char *name) {
    printf("Hello, %s!\n", name);
}

int main() {
    greetUser();
    return 0;
}