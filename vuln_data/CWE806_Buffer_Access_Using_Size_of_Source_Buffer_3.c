#include <stdio.h>
#include <string.h>

void copyBuffer(char *src) {
    char dest[10];
    size_t srcSize = strlen(src);
    if (srcSize >= sizeof(dest)) {
        printf("Source is too large, potential overflow detected.\n");
        return;
    }
    memcpy(dest, src, srcSize + 1);
    printf("Buffer copied successfully: %s\n", dest);
}

int main() {
    char source[] = "This is a very long string that exceeds the destination buffer size";
    copyBuffer(source);
    return 0;
}