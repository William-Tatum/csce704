#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void secure_memset(void *v, int c, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)v;
    while (n--) *p++ = c;
}

int main() {
    char secret_data[] = "Sensitive Information";
    
    // Zero out any buffer copies as well
    char *buf = malloc(sizeof(secret_data));
    if (buf) {
        strcpy(buf, secret_data);
        
        secure_memset(secret_data, 0, sizeof(secret_data));
        secure_memset(buf, 0, sizeof(secret_data));

        free(buf);
    }
    
    return 0;
}