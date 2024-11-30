#include <string.h>

void explicit_bzero(void *s, size_t n) {
    volatile unsigned char *p = s;
    while (n--) *p++ = 0;
}

void processSensitiveData() {
    char sensitiveData[128];
    strcpy(sensitiveData, "SuperSecretPassword");

    // Use sensitive data for some operations here

    explicit_bzero(sensitiveData, sizeof(sensitiveData));
}

int main() {
    processSensitiveData();
    return 0;
}