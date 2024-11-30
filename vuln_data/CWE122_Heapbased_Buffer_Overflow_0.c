#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable_function(const char *input) {
    char *buffer = (char *)malloc(10 * sizeof(char));
    if (buffer == NULL) {
        exit(1);
    }
    strcpy(buffer, input);
    printf("Buffer content: %s\n", buffer);
    free(buffer);
}

int main() {
    char input[20] = "ThisIsTooLongForTheBuffer";
    vulnerable_function(input);
    return 0;
}