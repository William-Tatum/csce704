#include <stdio.h>
#include <stdlib.h>

int main() {
    char user_input[256];
    printf("Enter a string: ");
    fgets(user_input, sizeof(user_input), stdin);
    printf(user_input);
    return 0;
}