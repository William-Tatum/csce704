#include <stdio.h>
#include <string.h>

int main() {
    const char src[] = "Hello, World!";
    char dest[20];

    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';

    printf("Copied string: %s\n", dest);
    return 0;
}