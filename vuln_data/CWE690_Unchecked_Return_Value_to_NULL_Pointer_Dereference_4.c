#include <stdio.h>
#include <stdlib.h>

char* risky_function() {
    char *ptr = (char *)malloc(256);
    if (ptr == NULL) {
        return NULL;
    }
    // Some operations on ptr
    return ptr;
}

int main() {
    char *data = risky_function();
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    // Safe to use data since it is checked
    printf("Data allocation succeeded\n");

    free(data);
    return 0;
}