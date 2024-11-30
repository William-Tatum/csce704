#include <stdio.h>
#include <string.h>

void copy_string(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer contents: %s\n", buffer);
}

int main() {
    char *large_input = "This is a very long string that will overflow the buffer!";
    copy_string(large_input);
    return 0;
}