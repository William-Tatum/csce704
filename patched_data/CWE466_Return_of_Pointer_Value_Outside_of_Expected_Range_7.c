#include <stdio.h>
#include <stdlib.h>

char* getBufferSafely(int index) {
    static char buffer[10] = "abcdefghi";
    if (index < 0 || index >= 9) {
        return NULL; 
    }
    return &buffer[index]; 
}

int main() {
    char* ptr = getBufferSafely(8);
    if (ptr) {
        printf("%c\n", *ptr);
    } else {
        printf("Pointer is out of buffer range\n");
    }
    return 0;
}