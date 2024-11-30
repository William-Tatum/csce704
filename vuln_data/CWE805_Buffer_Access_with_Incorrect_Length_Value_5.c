#include <stdio.h>
#include <string.h>

void unsafeCopy(char *source) {
    char destination[10];
    int length = 20; // Incorrect length value
    strncpy(destination, source, length);
    printf("Copied string: %s\n", destination);
}

int main() {
    char source[] = "This is a very long string that exceeds the buffer size";
    unsafeCopy(source);
    return 0;
}