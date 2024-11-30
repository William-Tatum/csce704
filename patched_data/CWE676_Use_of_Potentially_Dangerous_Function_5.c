#include <stdio.h>
#include <string.h>

void safe_strcpy(char *dest, size_t dest_size, const char *src) {
    if (strnlen(src, dest_size) < dest_size) {
        strcpy(dest, src);
    } else {
        strncpy(dest, src, dest_size - 1);
        dest[dest_size - 1] = '\0';
        fprintf(stderr, "Input truncated to prevent buffer overflow.\n");
    }
}

int main() {
    char buffer[10];
    const char *dangerous_input = "TooLongInput";
    safe_strcpy(buffer, sizeof(buffer), dangerous_input);
    printf("Buffer content: %s\n", buffer);
    return 0;
}