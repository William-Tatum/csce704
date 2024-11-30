#include <stdio.h>
#include <string.h>

void buffer_underwrite() {
    char buffer[10];
    char *ptr = buffer + 5;
    strncpy(ptr - 6, "Test String", 11);
    printf("Buffer: %s\n", buffer);
}

int main() {
    buffer_underwrite();
    return 0;
}