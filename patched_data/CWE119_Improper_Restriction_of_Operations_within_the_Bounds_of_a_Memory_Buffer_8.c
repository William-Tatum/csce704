#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *input = "This is a string longer than ten characters";
    
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    
    printf("Buffer content: %s\n", buffer);
    return 0;
}