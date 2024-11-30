#include <stdio.h>
#include <string.h>

void bufferOverreadExample() {
    char buffer[10] = "123456789";
    int i;
    for (i = 0; i <= 10; i++) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    bufferOverreadExample();
    return 0;
}