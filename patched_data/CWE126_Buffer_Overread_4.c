#include <stdio.h>
#include <string.h>

void safeFunction(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    int len = strlen(buffer);
    for (int i = 0; i < len; i++) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    char data[] = "HelloWorld!";
    safeFunction(data);
    return 0;
}