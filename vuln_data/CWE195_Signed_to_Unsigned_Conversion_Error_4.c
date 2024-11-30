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
    unsigned int unsigned_value = (unsigned int)signed_value;
    char *buffer = malloc(unsigned_value);
    if (!buffer) {
        printf("Memory allocation error\n");
        return 1;
    }
    memset(buffer, 0, unsigned_value);
    free(buffer);
    return 0;
}