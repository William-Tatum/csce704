#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    printf("Enter some input: ");
    fgets(buffer, 100, stdin);
    printf("You entered: %s\n", buffer);
    return 0;
}