#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';
    printf("You entered: %s\n", input);
    return 0;
}