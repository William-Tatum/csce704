#include <string.h>

volatile void *prevent_opt;

void secure_clear_memory(char *sensitive_data, size_t size) {
    volatile char *p = sensitive_data;
    while (size--) {
        *p++ = 0;
    }
    prevent_opt = memset((void *)sensitive_data, 0, size);
    asm volatile("" : : "g"(sensitive_data) : "memory");
}

int main() {
    char sensitive_info[] = "TopSecret123";
    secure_clear_memory(sensitive_info, sizeof(sensitive_info) - 1);
    return 0;
}