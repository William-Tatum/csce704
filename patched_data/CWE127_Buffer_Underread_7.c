#include <stdio.h>
#include <string.h>

void readBuffer(int index) {
    char buffer[10];
    strncpy(buffer, "Sensitive", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    if (index < 0 || index >= strlen(buffer)) {
        printf("Index out of bounds\n");
        return;
    }

    printf("Character at index %d: %c\n", index, buffer[index]);
}

int main() {
    int testIndex = 0;
    readBuffer(testIndex);
    return 0;
}