#include <stdio.h>
#include <stdlib.h>

char* getStringInRange() {
    char* buffer = (char*)malloc(10 * sizeof(char));
    if (!buffer) return NULL;
    for (int i = 0; i < 10; i++) {
        buffer[i] = 'A' + i;
    }
    return buffer + 5; // Returning a pointer to the middle of the buffer
}

int main() {
    char* str = getStringInRange();
    if (str) {
        printf("Partial string: %s\n", str); // May access out-of-range memory
        free(str - 5); // Correctly free the start of the buffer
    }
    return 0;
}