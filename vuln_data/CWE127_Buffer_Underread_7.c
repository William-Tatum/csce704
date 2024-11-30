#include <stdio.h>
#include <string.h>

void readBuffer(int index) {
    char buffer[10];
    strcpy(buffer, "Sensitive");

    if (index < 0 || index >= sizeof(buffer)) {
        printf("Index out of bounds\n");
        return;
    }

    printf("Character at index %d: %c\n", index, buffer[index]);
}

int main() {
    int testIndex = -1;
    readBuffer(testIndex);
    return 0;
}