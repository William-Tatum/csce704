#include <stdio.h>
#include <stdlib.h>

void log_message(const char* format, const char* message) {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%s", message);
    printf("%s\n", buffer);
}

int main() {
    char user_input[256];
    printf("Enter a message:\n");
    fgets(user_input, sizeof(user_input), stdin);

    log_message("%s", user_input);
    return 0;
}