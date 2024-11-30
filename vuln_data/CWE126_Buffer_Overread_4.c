#include <stdio.h>
#include <string.h>

void unsafeFunction(const char *input) {
    char buffer[10];
    strcpy(buffer, input);
    int len = strlen(buffer);
    for (int i = 0; i <= len; i++) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    char data[] = "HelloWorld!"; // Input larger than buffer
    unsafeFunction(data);
    return 0;
}