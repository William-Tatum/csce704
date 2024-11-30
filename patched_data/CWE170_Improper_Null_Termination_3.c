#include <stdio.h>
#include <string.h>

void safeFunction(const char *source) {
    char buffer[10];
    if (strlen(source) < sizeof(buffer)) {
        strcpy(buffer, source);
    } else {
        printf("Input too long, truncating to fit buffer.\n");
        strncpy(buffer, source, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';
    }
    printf("Buffer content: %s\n", buffer);
}

int main() {
    const char *input = "Very long input string";
    safeFunction(input);
    return 0;
}