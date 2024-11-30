#include <string.h>
#include <stdio.h>

void unsafe_copy(char *dest, const char *src, size_t dest_size) {
    strncpy(dest, src, dest_size);
}

int main() {
    char src[] = "Hello, World!";
    char dest[5];
    
    unsafe_copy(dest, src, sizeof(dest));

    printf("%s\n", dest);
    return 0;
}