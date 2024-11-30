#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *source) {
    char destination[10];
    size_t sourceSize = strlen(source);
    if (sourceSize >= sizeof(destination)) {
        printf("Source size is too large. Possible overflow.\n");
        return;
    }
    memcpy(destination, source, sourceSize);
    destination[sourceSize] = '\0';
    printf("Copied data: %s\n", destination);
}

int main() {
    char largeBuffer[] = "This is a very large buffer that can cause overflow";
    vulnerableFunction(largeBuffer);
    return 0;
}