#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char *ptr = buffer;
    strcpy(buffer, "hello");
    ptr -= 1;
    *ptr = 'X';
    printf("%s\n", buffer);
    return 0;
}