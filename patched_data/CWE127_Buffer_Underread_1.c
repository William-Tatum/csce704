#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "example");
    char *ptr = buffer + strlen(buffer) - 1;
    
    for (int i = 0; i < 10; i++) {
        if (ptr >= buffer) {
            printf("%c\n", *ptr);
            ptr--;
        }
    }

    return 0;
}