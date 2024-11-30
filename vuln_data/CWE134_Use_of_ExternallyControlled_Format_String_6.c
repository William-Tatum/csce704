#include <stdio.h>
#include <stdlib.h>

void log_message(const char *user_input) {
    // Vulnerable code: the format string comes from an external source and is not validated
    printf(user_input);
}

int main() {
    char user_input[256];
    printf("Enter a message: ");
    fgets(user_input, sizeof(user_input), stdin);
    log_message(user_input);
    return 0;
}