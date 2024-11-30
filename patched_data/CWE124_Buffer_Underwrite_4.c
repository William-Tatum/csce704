#include <stdio.h>
#include <string.h>

void buffer_proper_write() {
    char buffer[16];
    strncpy(buffer, "Test String", 10);
    buffer[10] = '\0';  // Ensure null-termination
    printf("Buffer: %s\n", buffer);
}

int main() {
    buffer_proper_write();
    return 0;
}