#include <stdio.h>

void greetUser(const char *name) {
    if (name != NULL) {
        printf("Hello, %s!\n", name);
    } else {
        printf("Hello!\n");
    }
}

int main() {
    char name[50];
    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';
        }
    } else {
        name[0] = '\0';
    }
    greetUser(name);
    return 0;
}