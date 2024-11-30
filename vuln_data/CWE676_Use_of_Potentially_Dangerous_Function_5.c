#include <stdio.h>
#include <string.h>

void safe_strcpy(char *dest, size_t dest_size, const char *src) {
    if (strlen(src) < dest_size) {
        strcpy(dest, src);
    } else {
        // Handle the error, e.g., truncate or exit
        fprintf(stderr, "Buffer overflow risk, copy aborted.\n");
    }
}

int main() {
    char buffer[10];
    const char *dangerous_input = "TooLongInput";
    safe_strcpy(buffer, sizeof(buffer), dangerous_input);
    printf("Buffer content: %s\n", buffer);
    return 0;
}