#include <stdio.h>
#include <string.h>

void safeFunction(const char *source) {
    char destination[10];
    strncpy(destination, source, sizeof(destination) - 1);
    destination[9] = '\0';
    printf("Copied string: %s\n", destination);
}

int main() {
    char largeBuffer[] = "This is a very large buffer that could cause overflow";
    safeFunction(largeBuffer);
    return 0;
}