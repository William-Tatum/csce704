#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char *input = "PotentiallyDangerousFunction";

    if (strlen(input) < sizeof(buffer)) {
        strcpy(buffer, input);
        printf("Buffer content: %s\n", buffer);
    } else {
        printf("Input is too large for the buffer\n");
    }

    return 0;
}