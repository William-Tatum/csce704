#include <stdio.h>

void processBuffer(unsigned int index) {
    char buffer[50];
    if (index >= sizeof(buffer)) {
        printf("Index is out of bounds\n");
        return;
    }

    int signedIndex = (int)index;
    buffer[signedIndex] = 'A';
    printf("Buffer updated at index %d\n", signedIndex);
}

int main() {
    unsigned int index = 100;
    processBuffer(index);

    return 0;
}