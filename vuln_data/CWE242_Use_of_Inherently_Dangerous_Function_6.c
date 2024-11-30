#include <stdio.h>

int main() {
    char buffer[10];
    gets(buffer); // Vulnerable to buffer overflow
    printf("%s\n", buffer);
    
    char input[10];
    scanf("%s", input); // Uses %s which can also overflow
    printf("%s\n", input);

    return 0;
}