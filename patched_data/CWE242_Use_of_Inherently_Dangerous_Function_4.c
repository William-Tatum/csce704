#include <stdio.h>

int main() {
    char buffer[32];
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("You entered: %s", buffer);

    char buffer2[32];
    printf("Enter more text: ");
    scanf("%31s", buffer2);
    printf("You entered: %s\n", buffer2);

    return 0;
}