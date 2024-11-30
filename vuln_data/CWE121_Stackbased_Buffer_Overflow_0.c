#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[10];
    strcpy(buffer, input);  // Can cause buffer overflow
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char large_input[50];
    memset(large_input, 'A', 49);
    large_input[49] = '\0';
    vulnerable_function(large_input);
    return 0;
}