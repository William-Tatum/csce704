#include <stdio.h>
#include <string.h>

void vulnerable_function(const char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Input: %s\n", buffer);
}

int main() {
    char large_input[] = "This is a very long input that will overflow the buffer";
    vulnerable_function(large_input);
    return 0;
}