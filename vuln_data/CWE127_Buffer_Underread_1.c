#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "example");
    char *ptr = buffer;
    
    for (int i = 0; i < 10; i++) {
        if (ptr - buffer > 0) {
            ptr--;
        }
        printf("%c\n", *ptr);
    }

    return 0;
}