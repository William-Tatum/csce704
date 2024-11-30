#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%s", "123456789012345");
    printf("Buffer content: %s\n", buffer);
    return 0;
}