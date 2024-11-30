#include <string.h>
#include <stdlib.h>

void copy_string(const char *input) {
    size_t len = strlen(input); 
    char *buffer = (char *)malloc(len + 1); 
    if (buffer != NULL) {
        strncpy(buffer, input, len);
        buffer[len] = '\0';
        free(buffer);
    }
}