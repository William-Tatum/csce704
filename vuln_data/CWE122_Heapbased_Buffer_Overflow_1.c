#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unsafe_copy(const char *input) {
    char *buffer = (char *)malloc(10 * sizeof(char));
    strcpy(buffer, input);
    printf("Buffer contents: %s\n", buffer);
    free(buffer);
}

int main() {
    char user_input[30];
    printf("Enter text: ");
    fgets(user_input, 30, stdin);
    unsafe_copy(user_input);
    return 0;
}