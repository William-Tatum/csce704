#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    char *ptr = buffer + 5;

    strncpy(buffer, "HelloWorld", BUFFER_SIZE);

    ptr -= 6;  // Underwrite: ptr points before the beginning of buffer
    *ptr = 'X';  // Writing 'X' before the buffer
    
    printf("Buffer content: %s\n", buffer);
    return 0;
}