#include <string.h>
#include <stdlib.h>

void secure_clear(volatile void *v, size_t n) {
    volatile unsigned char *p = v;
    while (n--) {
        *p++ = 0;
    }
}

int main() {
    char *password = malloc(32);
    if (password == NULL) {
        return 1;
    }
    strncpy(password, "SensitiveData123", 31);
    password[31] = '\0';
    
    // Sensitive operations with password
    
    secure_clear(password, 32);
    free(password);

    return 0;
}