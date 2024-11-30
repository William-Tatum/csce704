#include <stdio.h>
#include <string.h>

void print_first_char_before_buffer(char *input) {
    if (input == NULL || strlen(input) < 1) return;
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    char *ptr = buffer;
    if (ptr > buffer) {
        --ptr;
    }
    printf("Character before buffer start: %c\n", *ptr);
}

int main() {
    char *input = "Sensitive Data";
    print_first_char_before_buffer(input);
    return 0;
}