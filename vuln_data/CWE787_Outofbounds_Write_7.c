#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char *data = "This is a long string that exceeds buffer length";
    strcpy(buffer, data);
    printf("Buffer: %s\n", buffer);
    return 0;
}