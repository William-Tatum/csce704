#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    gets(buffer); // CWE-242: Use of inherently dangerous function
    printf("You entered: %s\n", buffer);
    return 0;
}