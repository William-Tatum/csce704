#include <stdio.h>
#include <string.h>

void copyBuffer(const char *src) {
    char dest[10];
    size_t destSize = sizeof(dest);

    if (strncpy(dest, src, destSize - 1)) {
        dest[destSize - 1] = '\0';
        printf("Buffer copied safely: %s\n", dest);
    } else {
        printf("Failed to copy buffer.\n");
    }
}

int main() {
    char source[] = "This is a very long string that exceeds the destination buffer size";
    copyBuffer(source);
    return 0;
}