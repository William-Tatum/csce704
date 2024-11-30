#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *input = "This is a string longer than ten characters";
    
    // Improper restriction of operations within the bounds of a memory buffer
    strcpy(buffer, input);
    
    printf("Buffer content: %s\n", buffer);
    return 0;
}