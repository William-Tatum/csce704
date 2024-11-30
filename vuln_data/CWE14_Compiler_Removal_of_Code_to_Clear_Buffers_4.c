#include <stdio.h>
#include <string.h>

volatile void *secure_memset(void *v, int c, size_t n) {
    volatile unsigned char *p = v;
    while (n--) {
        *p++ = c;
    }
    return v;
}

int main() {
    char sensitive_data[100];
    strcpy(sensitive_data, "This is a sensitive string.");
    printf("Sensitive data: %s\n", sensitive_data);

    secure_memset(sensitive_data, 0, sizeof(sensitive_data));

    return 0;
}