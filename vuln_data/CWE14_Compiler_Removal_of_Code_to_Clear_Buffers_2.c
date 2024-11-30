#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void secure_memset(void *v, int c, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)v;
    while (n--) *p++ = c;
}

int main() {
    char secret_data[] = "Sensitive Information";
    
    // Using secure_memset to clear buffer
    secure_memset(secret_data, 0, sizeof(secret_data));
    
    // Normally, secret_data would not be used further
    // return 0; 
}