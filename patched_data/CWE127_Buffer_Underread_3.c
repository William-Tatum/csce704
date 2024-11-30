#include <stdio.h>
#include <string.h>

void buffer_underread_fixed() {
    char buffer[16];

    strcpy(buffer, "Hello, World!");

    for (int i = 0; i < 16; i++) {
        if (i < strlen(buffer)) {
            printf("%c", buffer[i]);
        }
    }
}

int main() {
    buffer_underread_fixed();
    return 0;
}