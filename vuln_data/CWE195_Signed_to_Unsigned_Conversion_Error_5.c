#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable_function(int input_size) {
    if (input_size < 0) {
        printf("Error: Input size cannot be negative\n");
        return;
    }
    
    // Cast of input size to unsigned, potentially dangerous if input_size is negative
    size_t size = (size_t)input_size;
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    
    snprintf(buffer, size, "This is a test");
    printf("%s\n", buffer);
    free(buffer);
}

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    vulnerable_function(size);
    return 0;
}