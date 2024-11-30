#include <stdio.h>

char* getData(const char* buffer, size_t size, int index) {
    if (index < 0 || (size_t)index >= size - 1) {
        return NULL;
    }
    return (char*)(buffer + index);
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