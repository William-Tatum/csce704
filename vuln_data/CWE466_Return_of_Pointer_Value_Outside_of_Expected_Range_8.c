#include <stdio.h>

char* getData(char* buffer, size_t size, int index) {
    if (index < 0 || index >= size) {
        return NULL;
    }
    return buffer + index;
}

int main() {
    char array[10] = "ABCDEFGHI";
    char *ptr = getData(array, sizeof(array), 5);
    if (ptr != NULL) {
        printf("Data: %c\n", *ptr);
    } else {
        printf("Error: Out of range\n");
    }
    return 0;
}