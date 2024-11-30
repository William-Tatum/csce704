#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, World!";
    char destination[6];

    strncpy(destination, source, sizeof(destination));

    printf("Destination: %s\n", destination);
    return 0;
}