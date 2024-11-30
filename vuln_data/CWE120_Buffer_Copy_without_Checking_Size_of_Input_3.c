#include <stdio.h>
#include <string.h>

void copy_input(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Copied data: %s\n", buffer);
}

int main() {
    char input_buffer[100];
    printf("Enter some data: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    copy_input(input_buffer);
    return 0;
}