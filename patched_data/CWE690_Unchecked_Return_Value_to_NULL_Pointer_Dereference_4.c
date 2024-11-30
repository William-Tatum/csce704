#include <stdio.h>
#include <stdlib.h>

char* risky_function() {
    char *ptr = (char *)malloc(256);
    if (ptr == NULL) {
        return NULL;
    }
    // Initialize the allocated memory to prevent use of uninitialized memory
    memset(ptr, 0, 256);
    return ptr;
}

int main() {
    char *data = risky_function();
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    printf("Data allocation succeeded\n");

    free(data);
    return 0;
}