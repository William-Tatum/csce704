#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[256];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    if (strchr(input, '\n')) {
        input[strcspn(input, "\n")] = '\0';
    }
    printf("You entered: %s\n", input);
    return 0;
}