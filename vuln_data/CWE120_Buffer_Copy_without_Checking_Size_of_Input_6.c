#include <stdio.h>
#include <string.h>

void unsafeFunction(char *input) {
    char buffer[10];
    strcpy(buffer, input);  // classic buffer overflow, no size check
    printf("Buffer contents: %s\n", buffer);
}

int main() {
    char input[20];
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    unsafeFunction(input);
    return 0;
}