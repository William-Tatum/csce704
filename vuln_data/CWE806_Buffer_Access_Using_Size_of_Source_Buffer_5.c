#include <stdio.h>
#include <string.h>

void potentiallyUnsafeFunction(char *source) {
    char destination[10];
    strncpy(destination, source, sizeof(source)); // Unsafe copying
    destination[9] = '\0'; 
    printf("Copied string: %s\n", destination);
}

int main() {
    char largeBuffer[] = "This is a very large buffer that could cause overflow";
    potentiallyUnsafeFunction(largeBuffer);
    return 0;
}