#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[256];
    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';
    printf("You entered: %s\n", input);
    return 0;
}