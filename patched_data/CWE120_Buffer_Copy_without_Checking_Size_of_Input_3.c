#include <stdio.h>
#include <string.h>

void copy_input(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Copied data: %s\n", buffer);
}

int main() {
    char input_buffer[100];
    printf("Enter some data: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    copy_input(input_buffer);
    return 0;
}