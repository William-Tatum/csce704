#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    int i;
    for (i = 0; i <= 10; i++) {
        buffer[i] = 'A';
    }
    printf("Buffer content: %s\n", buffer);
    return 0;
}