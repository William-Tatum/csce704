#include <stdio.h>
#include <string.h>

void secure_function(char *input) {
    char dest[10];
    strncpy(dest, input, sizeof(dest) - 1);
    dest[9] = '\0';
    printf("Copied string: %s\n", dest);
}

int main() {
    char large_input[100] = "This is a very large input string that exceeds the destination buffer size.";
    secure_function(large_input);
    return 0;
}