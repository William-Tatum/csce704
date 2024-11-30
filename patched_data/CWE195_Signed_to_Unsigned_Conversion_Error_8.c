#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_value() {
    return -1; // Simulated failure returning a negative value
}

int main() {
    int signedValue = get_value();
    if (signedValue < 0) {
        printf("Error: Negative value encountered\n");
        return 1;
    }
    
    unsigned int unsignedValue = (unsigned int)signedValue;

    if (unsignedValue > 0) {
        char *buffer = malloc(unsignedValue);
        
        if (buffer == NULL) {
            printf("Error: Memory allocation failed\n");
            return 1;
        }

        strncpy(buffer, "Example", unsignedValue - 1);
        buffer[unsignedValue - 1] = '\0';

        printf("Buffer content: %s\n", buffer);
        free(buffer);
    } else {
        printf("No allocation needed as unsignedValue is zero\n");
    }

    return 0;
}