#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_value() {
    return -5;
}

int main() {
    int signed_value = get_value();
    if (signed_value < 0) {
        printf("Error: Negative value detected\n");
        return 1;
    }
    
    size_t unsigned_value = (size_t)signed_value;
    if (unsigned_value == 0) {
        printf("Error: Value is zero or negative\n");
        return 1;
    }

    char *buffer = malloc(unsigned_value);
    if (!buffer) {
        printf("Memory allocation error\n");
        return 1;
    }
    memset(buffer, 0, unsigned_value);
    free(buffer);
    return 0;
}