#include <string.h>
#include <stdlib.h>

void secure_scrub(void *ptr, size_t len) {
    volatile unsigned char *p = (volatile unsigned char *)ptr;
    while (len--) {
        *p++ = 0;
    }
}

int main() {
    char *sensitive_data = (char *)malloc(100 * sizeof(char));
    if (sensitive_data == NULL) {
        return 1;
    }
    strcpy(sensitive_data, "Sensitive Information");
    secure_scrub(sensitive_data, 100);
    free(sensitive_data);
    return 0;
}