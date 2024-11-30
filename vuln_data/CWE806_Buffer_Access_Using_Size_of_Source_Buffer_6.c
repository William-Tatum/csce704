#include <stdio.h>
#include <string.h>

void copyStrings(const char *source) {
    char dest[10];
    strncpy(dest, source, sizeof(source));
    dest[sizeof(dest) - 1] = '\0';
    printf("Copied string: %s\n", dest);
}

int main() {
    char largeBuffer[100] = "This is a very large buffer that will overflow the destination buffer.";
    copyStrings(largeBuffer);
    return 0;
}