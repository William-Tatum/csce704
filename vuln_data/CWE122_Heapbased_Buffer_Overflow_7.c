#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable_function(const char *input) {
    char *heap_buffer = (char *)malloc(10 * sizeof(char));
    strcpy(heap_buffer, input);
    printf("Buffer content: %s\n", heap_buffer);
    free(heap_buffer);
}

int main() {
    char user_input[20];
    printf("Enter some text: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0';
    vulnerable_function(user_input);
    return 0;
}