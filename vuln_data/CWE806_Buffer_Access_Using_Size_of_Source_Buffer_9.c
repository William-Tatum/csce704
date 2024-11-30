#include <stdio.h>
#include <string.h>

#define SOURCE_SIZE 100
#define DEST_SIZE 50

void copyData(char *source) {
    char destination[DEST_SIZE];
    memcpy(destination, source, DEST_SIZE);
    destination[DEST_SIZE - 1] = '\0'; // null-terminate
    printf("%s\n", destination);
}

int main() {
    char source[SOURCE_SIZE];
    memset(source, 'A', SOURCE_SIZE - 1);
    source[SOURCE_SIZE - 1] = '\0';
    copyData(source);
    return 0;
}