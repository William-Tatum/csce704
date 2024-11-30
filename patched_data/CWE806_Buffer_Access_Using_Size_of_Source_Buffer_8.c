#include <stdio.h>
#include <string.h>

void secureFunction(const char *source) {
    char destination[10];
    size_t destinationSize = sizeof(destination);
    strncpy(destination, source, destinationSize - 1);
    destination[destinationSize - 1] = '\0';
    printf("Copied data: %s\n", destination);
}

int main() {
    char largeBuffer[] = "This is a very large buffer that can cause overflow";
    secureFunction(largeBuffer);
    return 0;
}