#include <stdio.h>
#include <string.h>

void secure_memzero(void *v, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)v;
    while (n--) *p++ = 0;
}

int main() {
    char sensitive_data[128];
    strncpy(sensitive_data, "VerySensitiveData123", sizeof(sensitive_data) - 1);
    sensitive_data[sizeof(sensitive_data) - 1] = '\0';

    secure_memzero(sensitive_data, sizeof(sensitive_data));

    return 0;
}