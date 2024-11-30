#include <stdio.h>
#include <limits.h>

int main() {
    char buffer[32];
    printf("Enter some text: ");
    gets(buffer); // CWE-242: Use of inherently dangerous function
    printf("You entered: %s\n", buffer);

    char buffer2[32];
    printf("Enter more text: ");
    scanf("%31s", buffer2); // Mitigated use of scanf to prevent overflow
    printf("You entered: %s\n", buffer2);

    return 0;
}