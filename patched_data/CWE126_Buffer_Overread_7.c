#include <stdio.h>
#include <string.h>

void readData(char *input) {
    char buffer[10];
    size_t buffer_size = sizeof(buffer) - 1;
    size_t i;

    strncpy(buffer, input, buffer_size);
    buffer[buffer_size] = '\0';
    
    for (i = 0; i < buffer_size && buffer[i] != '\0'; i++) {
        printf("%c", buffer[i]);
    }
}

int main() {
    char data[] = "This is a test string longer than buffer";
    readData(data);
    return 0;
}