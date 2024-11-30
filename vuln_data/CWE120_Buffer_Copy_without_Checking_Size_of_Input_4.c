#include <string.h>
#include <stdio.h>

void unsafe_copy(const char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char large_input[20] = "This is too long";
    unsafe_copy(large_input);
    return 0;
}