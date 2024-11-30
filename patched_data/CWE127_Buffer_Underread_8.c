#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strncpy(buffer, "Hello", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    int index = 4; // Example of valid index
    if (index >= 0 && index < strlen(buffer)) {
        printf("Character: %c\n", buffer[index]);
    } else {
        printf("Index out of bounds\n");
    }
    
    return 0;
}