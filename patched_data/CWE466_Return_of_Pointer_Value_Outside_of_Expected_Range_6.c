#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getStringInRange() {
    char* buffer = (char*)malloc(11 * sizeof(char)); // Allocate extra for null terminator
    if (!buffer) return NULL;
    for (int i = 0; i < 10; i++) {
        buffer[i] = 'A' + i;
    }
    buffer[10] = '\0'; // Null-terminate the buffer
    return buffer + 5;
}

int main() {
    char* str = getStringInRange();
    if (str) {
        printf("Partial string: %.5s\n", str); // Limit string output to 5 characters
        free(str - 5);
    }
    return 0;
}