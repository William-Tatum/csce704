#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_string(const char *input) {
    size_t len = strlen(input);
    char *buf = (char *)malloc(len + 1);
    if (buf == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strncpy(buf, input, len);
    buf[len] = '\0';
    printf("Copied string: %s\n", buf);
    free(buf);
}

int main() {
    const char *text = "This is a test string";
    copy_string(text);
    return 0;
}