#include <stdio.h>
#include <string.h>

int main() {
    char buffer[11]; 
    strncpy(buffer, "1234567890", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    for (int i = 0; i < sizeof(buffer) - 1; i++) {
        printf("%c\n", buffer[i]);
    }
    return 0;
}