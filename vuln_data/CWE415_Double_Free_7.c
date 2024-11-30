#include <stdlib.h>
#include <stdio.h>

int main() {
    char *ptr = (char *)malloc(10);
    if (ptr == NULL) {
        return 1;
    }
    
    free(ptr);
    
    // Vulnerable code: double free
    free(ptr);
    
    return 0;
}