#include <stdio.h>

int main() {
    char buffer[10];
    gets(buffer);
    printf("You entered: %s\n", buffer);

    char buffer2[10];
    scanf("%s", buffer2);
    printf("You entered: %s\n", buffer2);

    return 0;
}