#include <stdio.h>

void processBuffer(unsigned int index) {
    char buffer[50];
    if (index >= sizeof(buffer)) {
        printf("Index is out of bounds\n");
        return;
    }

    buffer[index] = 'A';
    printf("Buffer updated at index %u\n", index);
}

int main() {
    unsigned int index = 100;
    processBuffer(index);

    return 0;
}