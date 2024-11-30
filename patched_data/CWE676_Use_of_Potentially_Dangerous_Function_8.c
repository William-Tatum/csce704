#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char *input = "PotentiallyDangerousFunction";

    if (strlen(input) < sizeof(buffer)) {
        strncpy(buffer, input, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';
        printf("Buffer content: %s\n", buffer);
    } else {
        printf("Input is too large for the buffer\n");
    }

    return 0;
}