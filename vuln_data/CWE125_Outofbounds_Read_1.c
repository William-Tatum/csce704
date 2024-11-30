#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "HelloWorld");
    printf("Accessing buffer out-of-bounds: %c\n", buffer[10]);
    return 0;
}