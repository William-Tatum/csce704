#include <stdio.h>
#include <string.h>

void function(char *input) {
    char buffer[8];
    strcpy(buffer, input);
}

int main() {
    char large_input[] = "This is a very long string that will cause a buffer overflow!";
    function(large_input);
    return 0;
}