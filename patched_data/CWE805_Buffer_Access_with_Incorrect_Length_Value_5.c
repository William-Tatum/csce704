#include <stdio.h>
#include <string.h>

void safeCopy(char *source) {
    char destination[10];
    strncpy(destination, source, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';
    printf("Copied string: %s\n", destination);
}

int main() {
    char source[] = "This is a very long string that exceeds the buffer size";
    safeCopy(source);
    return 0;
}