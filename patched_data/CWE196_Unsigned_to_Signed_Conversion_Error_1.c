#include <stdio.h>
#include <limits.h>

void processBuffer(unsigned int size) {
    if (size >= 100) {
        printf("Invalid buffer size\n");
        return;
    }
    
    char buffer[100];

    for (unsigned int i = 0; i < size; i++) {
        buffer[i] = 'A';
    }
    
    buffer[size] = '\0';
    printf("Buffer: %s\n", buffer);
}

int main() {
    unsigned int size = 150;
    processBuffer(size);

    size = UINT_MAX;
    processBuffer(size);

    return 0;
}