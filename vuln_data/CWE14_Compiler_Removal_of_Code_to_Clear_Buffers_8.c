#include <stdio.h>
#include <string.h>

void secure_memzero(void *v, size_t n) {
    volatile unsigned char *p = v;
    while (n--) *p++ = 0;
}

int main() {
    char sensitive_data[128];
    strcpy(sensitive_data, "VerySensitiveData123");

    secure_memzero(sensitive_data, sizeof(sensitive_data));

    return 0;
}