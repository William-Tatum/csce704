#include <string.h>

void secure_clear(void *v, size_t n) {
    volatile unsigned char *p = v;
    while (n--) {
        *p++ = 0;
    }
}

void handle_sensitive_data(char *sensitive_data, size_t size) {
    if (sensitive_data == NULL) return;
    // Process the sensitive data
    strncpy(sensitive_data, "ProcessedData", size - 1);
    sensitive_data[size - 1] = '\0';
    
    secure_clear(sensitive_data, strlen(sensitive_data));
}

int main() {
    char sensitive_data[100] = "SensitiveInformation";
    handle_sensitive_data(sensitive_data, sizeof(sensitive_data));
    return 0;
}