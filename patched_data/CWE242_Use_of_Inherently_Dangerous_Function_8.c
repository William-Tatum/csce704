#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    printf("You entered: %s\n", buffer);
    
    char buffer2[10];
    scanf("%9s", buffer2);
    printf("You entered: %s\n", buffer2);

    return 0;
}