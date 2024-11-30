#include <string.h>
#include <stdio.h>

int main() {
    char source[10] = "123456789";
    char destination[10];
    int length = 15;
    if (length > sizeof(destination) - 1) {
        length = sizeof(destination) - 1;
    }
    strncpy(destination, source, length);
    destination[length] = '\0';
    printf("Destination: %s\n", destination);
    return 0;
}