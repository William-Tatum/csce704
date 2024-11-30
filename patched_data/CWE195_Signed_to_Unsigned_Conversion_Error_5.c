#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_function(int input_size) {
    if (input_size <= 0) {
        printf("Error: Input size must be positive\n");
        return;
    }
    
    size_t size = (size_t)input_size;
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    
    if (snprintf(buffer, size, "This is a test") >= size) {
        printf("Error: Buffer overflow prevented\n");
    } else {
        printf("%s\n", buffer);
    }
    
    free(buffer);
}

int main() {
    int size;
    printf("Enter size: ");
    if (scanf("%d", &size) != 1) {
        printf("Error: Invalid input\n");
        return 1;
    }
    secure_function(size);
    return 0;
}