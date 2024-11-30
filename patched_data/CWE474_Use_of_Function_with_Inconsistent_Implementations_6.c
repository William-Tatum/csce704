#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    size_t size = 100;
    
    buffer = (char *)malloc(size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

#ifdef _WIN32
    if (strcpy_s(buffer, size, "This is Windows specific implementation.") != 0) {
        fprintf(stderr, "String copy failed\n");
        free(buffer);
        return 1;
    }
#elif defined(__linux__)
    strncpy(buffer, "This is Linux specific implementation.", size - 1);
    buffer[size - 1] = '\0';
#elif defined(__APPLE__)
    strncpy(buffer, "This is macOS specific implementation.", size - 1);
    buffer[size - 1] = '\0';
#else
    strncpy(buffer, "This platform is not explicitly handled.", size - 1);
    buffer[size - 1] = '\0';
#endif

    printf("Message: %s\n", buffer);

    free(buffer);
    return 0;
}