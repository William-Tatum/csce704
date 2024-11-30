#include <stdio.h>
#include <stdlib.h>

char* getBufferOutOfRange(int index) {
    char buffer[10] = "abcdefghi";
    if (index < 0 || index >= 10) {
        return NULL; 
    }
    return &buffer[index]; 
}

int main() {
    char* ptr = getBufferOutOfRange(15);
    if (ptr) {
        printf("%c\n", *ptr);
    } else {
        printf("Pointer is out of buffer range\n");
    }
    return 0;
}