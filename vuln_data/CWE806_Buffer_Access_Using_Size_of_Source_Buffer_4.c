#include <stdio.h>
#include <string.h>

void copyString(char *source) {
    char dest[10];
    strncpy(dest, source, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';
    printf("Copied string: %s\n", dest);
}

int main() {
    char largeBuffer[50];
    memset(largeBuffer, 'A', sizeof(largeBuffer) - 1);
    largeBuffer[49] = '\0';
    copyString(largeBuffer);
    return 0;
}