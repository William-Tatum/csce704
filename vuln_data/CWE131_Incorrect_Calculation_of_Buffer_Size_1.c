#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void copy_data(const char *source) {
    size_t len = strlen(source);
    char *buffer = (char *)malloc(len); // Incorrect: does not account for the null terminator
    if (buffer == NULL) {
        return;
    }
    strcpy(buffer, source); // Potential buffer overflow
    printf("Copied data: %s\n", buffer);
    free(buffer);
}

int main() {
    const char *data = "This is a test string";
    copy_data(data);
    return 0;
}