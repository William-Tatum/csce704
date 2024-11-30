#include <string.h>
#include <stdio.h>

void buffer_copy(const char *src, size_t length) {
    char dest[10];
    if (length >= sizeof(dest)) {
        printf("Error: length exceeds buffer size\n");
        return;
    }
    memcpy(dest, src, length);
    dest[length] = '\0';
    printf("Copied string: %s\n", dest);
}

int main() {
    const char *data = "This is a sample string";
    buffer_copy(data, 9);
    buffer_copy(data, 15);
    return 0;
}