#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[] = "This is a very long string that will exceed the allocated buffer size.";
    size_t length = strlen(input);
    char *buffer = (char *)malloc(length + 1);
    if (buffer == NULL) {
        return 1;
    }
    strncpy(buffer, input, length);
    buffer[length] = '\0';
    printf("Buffer contains: %s\n", buffer);
    free(buffer);
    return 0;
}