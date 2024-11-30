#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString() {
    char* buffer = (char*)malloc(12 * sizeof(char));
    if (buffer == NULL) {
        exit(1);
    }
    strcpy(buffer, "HelloWorld!");
    return buffer;
}

int main() {
    char* str = getString();
    printf("String: %s\n", str);
    free(str);
    return 0;
}