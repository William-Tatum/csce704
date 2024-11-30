#include <stdio.h>
#include <stdlib.h>

void log_message(const char *user_input) {
    printf("%s", user_input);
}

int main() {
    char user_input[256];
    printf("Enter a message: ");
    fgets(user_input, sizeof(user_input), stdin);
    log_message(user_input);
    return 0;
}