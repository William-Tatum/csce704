#include <stdio.h>

int main() {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    printf("Input: %s", buffer);
    
    char input[50];
    printf("Enter text: ");
    scanf("%49s", input);
    printf("Entered: %s\n", input);

    return 0;
}