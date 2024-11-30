#include <stdio.h>

int main() {
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    printf("%s", buffer);
    
    char input[10];
    scanf("%9s", input);
    printf("%s\n", input);

    return 0;
}