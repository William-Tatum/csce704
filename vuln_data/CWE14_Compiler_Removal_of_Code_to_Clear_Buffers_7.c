#include <string.h>

void secure_clear(void *v, size_t n) {
    volatile unsigned char *p = v;
    while (n--) {
        *p++ = 0;
    }
}

void handle_sensitive_data(char *sensitive_data) {
    if (sensitive_data == NULL) return;
    // Process the sensitive data
    strcpy(sensitive_data, "ProcessedData");
    
    secure_clear(sensitive_data, strlen(sensitive_data));
}

int main() {
    char sensitive_data[100] = "SensitiveInformation";
    handle_sensitive_data(sensitive_data);
    return 0;
}