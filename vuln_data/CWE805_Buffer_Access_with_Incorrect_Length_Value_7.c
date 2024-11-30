#include <string.h>
#include <stdio.h>

void buffer_copy(char *src, int length) {
    char dest[10];
    if (length > sizeof(dest)) {
        printf("Error: length exceeds buffer size\n");
        return;
    }
    memcpy(dest, src, length);
    printf("Copied string: %.*s\n", length, dest);
}

int main() {
    char *data = "This is a sample string";
    buffer_copy(data, 15);
    buffer_copy(data, 25);
    return 0;
}