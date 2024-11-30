#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString() {
    char buffer[10];
    strcpy(buffer, "HelloWorld!");
    return buffer + 11; // Returning a pointer outside of the buffer's range
}

int main() {
    char* str = getString();
    printf("String: %s\n", str);
    return 0;
}