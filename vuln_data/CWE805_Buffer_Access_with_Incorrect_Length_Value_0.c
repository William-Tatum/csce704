#include <stdio.h>
#include <string.h>

void copy_data(char *source, size_t length) {
    char buffer[10];
    if (length > sizeof(buffer)) {
        printf("Error: Attempt to write beyond buffer size.\n");
        return;
    }
    memcpy(buffer, source, length);
    printf("Data copied: %.*s\n", (int)length, buffer);
}

int main() {
    char src[] = "This is a long test string that exceeds buffer size.";
    size_t len = strlen(src);
    copy_data(src, len);
    return 0;
}