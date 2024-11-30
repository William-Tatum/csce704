#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *data = "This is a long string that will overflow the buffer";
    strncpy(buffer, data, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("%s\n", buffer);
    return 0;
}