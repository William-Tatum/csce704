#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_string(const char *source) {
    size_t length = strlen(source); 
    char *buffer = (char *)malloc(length + 1);
    if (buffer == NULL) {
        fputs("Memory allocation failed\n", stderr);
        exit(1);
    }
    strcpy(buffer, source);
    printf("%s\n", buffer);
    free(buffer);
}

int main() {
    const char *my_string = "Hello, World!";
    copy_string(my_string);
    return 0;
}