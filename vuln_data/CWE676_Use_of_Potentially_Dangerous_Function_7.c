#include <stdio.h>
#include <string.h>

int main() {
    char buffer[50];
    strncpy(buffer, "This could be a very long input string", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("%s\n", buffer);
    return 0;
}