#include <string.h>

#if defined(_WIN32)
#include <windows.h>
#define secure_zero_memory SecureZeroMemory
#else
#define secure_zero_memory explicit_bzero
#endif

void secure_zero_memory(void *s, size_t n) {
    volatile unsigned char *p = s;
    while (n--) *p++ = 0;
}

void processSensitiveData() {
    char sensitiveData[128];
    strncpy(sensitiveData, "SuperSecretPassword", sizeof(sensitiveData) - 1);
    sensitiveData[sizeof(sensitiveData) - 1] = '\0';

    // Use sensitive data for some operations here

    secure_zero_memory(sensitiveData, sizeof(sensitiveData));
}

int main() {
    processSensitiveData();
    return 0;
}