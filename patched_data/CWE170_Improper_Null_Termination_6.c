#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, World!";
    char destination[6];

    strncpy(destination, source, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';

    printf("Destination: %s\n", destination);
    return 0;
}