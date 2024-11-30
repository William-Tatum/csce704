#include <stdio.h>
#include <string.h>

void copyString(const char *source) {
    char buffer[10];
    strncpy(buffer, source, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Copied string: %s\n", buffer);
}

int main() {
    const char *original = "This is a very long string";
    copyString(original);
    return 0;
}