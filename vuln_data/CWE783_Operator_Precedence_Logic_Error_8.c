#include <stdio.h>
#include <stdbool.h>

bool authenticate_user(const char* username, const char* password) {
    return (username == "admin" && password == "password123") || (username == "user" && password == "userpass");
}

int main() {
    const char* user = "admin";
    const char* pass = "wrongpass";

    if (authenticate_user(user, pass) == true)
        printf("Access granted.\n");
    else
        printf("Access denied.\n");

    return 0;
}