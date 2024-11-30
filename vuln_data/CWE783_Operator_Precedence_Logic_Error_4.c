#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool authenticate(const char* username, const char* password) {
    const char* correctUsername = "admin";
    const char* correctPassword = "secret";
    
    // Incorrect logic due to operator precedence
    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0 || true) {
        return true;
    } else {
        return false;
    }
}

int main() {
    const char* username = "user";
    const char* password = "pass";
    
    if (authenticate(username, password)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }
    
    return 0;
}