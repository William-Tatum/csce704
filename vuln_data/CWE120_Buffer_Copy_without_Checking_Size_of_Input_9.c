#include <stdio.h>
#include <string.h>

void copy_buffer(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char input_data[20] = "1234567890123456789";
    copy_buffer(input_data);
    return 0;
}