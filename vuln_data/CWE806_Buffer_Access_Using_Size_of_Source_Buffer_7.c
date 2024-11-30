#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char dest[10];
    strncpy(dest, input, sizeof(input));
    dest[9] = '\0';
    printf("Copied string: %s\n", dest);
}

int main() {
    char large_input[100] = "This is a very large input string that exceeds the destination buffer size.";
    vulnerable_function(large_input);
    return 0;
}