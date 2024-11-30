#include <string.h>
#include <stdio.h>

void safe_copy(char *dest, const char *src, size_t dest_size) {
    if (dest_size > 0) {
        strncpy(dest, src, dest_size - 1);
        dest[dest_size - 1] = '\0';
    }
}

int main() {
    char src[] = "Hello, World!";
    char dest[5];
    
    safe_copy(dest, src, sizeof(dest));

    printf("%s\n", dest);
    return 0;
}