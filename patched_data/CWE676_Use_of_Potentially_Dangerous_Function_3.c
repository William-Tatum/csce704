#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *input = "TooLongInputString";

    if (strlen(input) >= sizeof(buffer)) {
        fprintf(stderr, "Input is too long\n");
        return 1;
    }

    strcpy(buffer, input);
    printf("Buffer contains: %s\n", buffer);
    return 0;
}