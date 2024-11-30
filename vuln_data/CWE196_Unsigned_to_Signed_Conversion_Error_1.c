#include <stdio.h>
#include <limits.h>

void processBuffer(unsigned int size) {
    if (size > INT_MAX) {
        printf("Size is too large\n");
        return;
    }
    
    int signedSize = (int)size;
    char buffer[100];

    if (signedSize < 0 || signedSize >= 100) {
        printf("Invalid buffer size\n");
        return;
    }

    for (int i = 0; i < signedSize; i++) {
        buffer[i] = 'A';
    }
    
    buffer[signedSize] = '\0';
    printf("Buffer: %s\n", buffer);
}

int main() {
    unsigned int size = 150;
    processBuffer(size);

    size = UINT_MAX;
    processBuffer(size);

    return 0;
}