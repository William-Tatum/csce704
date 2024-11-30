#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";
    char dest[14];
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';
    printf("%s\n", dest);
    return 0;
}