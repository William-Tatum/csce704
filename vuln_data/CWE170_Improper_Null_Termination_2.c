#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";
    char dest[13];
    strncpy(dest, src, sizeof(dest));
    dest[sizeof(dest) - 1] = '\0';
    printf("%s\n", dest);
    return 0;
}