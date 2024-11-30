#include <stdio.h>
#include <string.h>

void copy_input(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Copied data: %s\n", buffer);
}

int main() {
    char input_data[20] = "ThisIsTooLongInput";
    copy_input(input_data);
    return 0;
}