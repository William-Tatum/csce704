#include <stdio.h>
#include <string.h>

void buffer_underwrite(char* input) {
    char buffer[10];
    int index = -5;
    strncpy(buffer + index, input, strlen(input)); // Underwrite vulnerability
    printf("Buffer contents: %s\n", buffer);
}

int main() {
    char* data = "testinput";
    buffer_underwrite(data);
    return 0;
}