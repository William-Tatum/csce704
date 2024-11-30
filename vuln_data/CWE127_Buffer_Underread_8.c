#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "Hello");
    
    int index = -1; // Example of potential under-read
    if (index >= 0 && index < sizeof(buffer)) {
        printf("Character: %c\n", buffer[index]);
    } else {
        printf("Index out of bounds\n");
    }
    
    return 0;
}