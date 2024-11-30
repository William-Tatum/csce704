#include <stdio.h>

int main() {
    char buffer[10];
    gets(buffer);
    printf("You entered: %s\n", buffer);
    return 0;
}