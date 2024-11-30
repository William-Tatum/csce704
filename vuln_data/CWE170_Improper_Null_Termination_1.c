#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, World!";
    char destination[6];
    strncpy(destination, source, 5);
    destination[5] = '\0';
    printf("%s\n", destination);
    return 0;
}