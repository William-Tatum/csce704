#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool authenticate_user(const char* username, const char* password) {
    return (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) || 
           (strcmp(username, "user") == 0 && strcmp(password, "userpass") == 0);
}

int main() {
    const char* user = "admin";
    const char* pass = "wrongpass";

    if (authenticate_user(user, pass))
        printf("Access granted.\n");
    else
        printf("Access denied.\n");

    return 0;
}