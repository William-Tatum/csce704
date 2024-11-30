#include <string.h>
#include <stdlib.h>

void copy_string(const char *input) {
    size_t len = strlen(input); 
    char *buffer = (char *)malloc(len); 
    if (buffer != NULL) {
        strcpy(buffer, input);
        // Use the buffer for further processing
        free(buffer);
    }
}