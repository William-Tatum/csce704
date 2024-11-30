#include <stdio.h>
#include <stdlib.h>

void log_message(const char* format, const char* message) {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), format, message);
    printf("%s\n", buffer);
}

int main() {
    char user_input[256];
    printf("Enter a message:\n");
    fgets(user_input, sizeof(user_input), stdin);

    char format_string[256];
    printf("Enter a format string:\n");
    fgets(format_string, sizeof(format_string), stdin);

    log_message(format_string, user_input);
    return 0;
}