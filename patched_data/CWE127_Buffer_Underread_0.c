#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "Hello");
    int index = 0;

    if (index >= 0 && index < sizeof(buffer)) {
        printf("Read character: %c\n", buffer[index]);
    } else {
        printf("Index out of bounds\n");
    }

    return 0;
}