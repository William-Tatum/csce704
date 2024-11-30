#include <stdio.h>
#include <string.h>

void readData(char *input) {
    char buffer[10];
    int i;

    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    
    for (i = 0; i <= sizeof(buffer); i++) {
        printf("%c", buffer[i]);
    }
}

int main() {
    char data[] = "This is a test string longer than buffer";
    readData(data);
    return 0;
}