#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void copy_data(const char *source) {
    size_t len = strlen(source) + 1;
    char *buffer = (char *)malloc(len);
    if (buffer == NULL) {
        return;
    }
    strncpy(buffer, source, len);
    printf("Copied data: %s\n", buffer);
    free(buffer);
}

int main() {
    const char *data = "This is a test string";
    copy_data(data);
    return 0;
}