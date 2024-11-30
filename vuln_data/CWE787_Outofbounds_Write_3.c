#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *source = "This is a string that is too long.";

    strcpy(buffer, source);

    printf("Buffer content: %s\n", buffer);
    return 0;
}