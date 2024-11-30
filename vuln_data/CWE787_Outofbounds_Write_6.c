#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *data = "This string is too long for the buffer";
    
    for (int i = 0; i <= strlen(data); i++) {
        buffer[i] = data[i];
    }
    
    printf("Buffer: %s\n", buffer);
    return 0;
}