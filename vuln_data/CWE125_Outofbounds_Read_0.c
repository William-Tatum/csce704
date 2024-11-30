#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "1234567890"); 
    for (int i = 0; i <= 10; i++) {
        printf("%c\n", buffer[i]);
    }
    return 0;
}