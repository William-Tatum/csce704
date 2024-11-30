#include <stdio.h>
#include <string.h>

int main() {
    char buffer[11];
    int i;
    for (i = 0; i < 10; i++) {
        buffer[i] = 'A';
    }
    buffer[10] = '\0';
    printf("Buffer content: %s\n", buffer);
    return 0;
}