#include <stdio.h>
#include <stdlib.h>

int main() {
    char user_input[256];
    printf("Enter a string: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        printf("%s", user_input);
    }
    return 0;
}