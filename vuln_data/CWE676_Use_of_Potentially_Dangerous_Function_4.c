#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    fgets(input, sizeof(input), stdin);
    printf("You entered: %s\n", input);
    return 0;
}