#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter some text: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
        printf("You entered: %s\n", input);
    }
    return 0;
}