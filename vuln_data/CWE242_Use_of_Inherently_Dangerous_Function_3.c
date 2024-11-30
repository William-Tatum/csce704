#include <stdio.h>

int main() {
    char buffer[100];
    gets(buffer);
    printf("Input: %s\n", buffer);
    
    char input[50];
    printf("Enter text: ");
    scanf("%50s", input);
    printf("Entered: %s\n", input);

    return 0;
}