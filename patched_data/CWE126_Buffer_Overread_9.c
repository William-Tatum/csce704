#include <stdio.h>
#include <string.h>

void readBuffer(const char *input) {
    char buffer[10];
    unsigned int i;

    if (strlen(input) >= sizeof(buffer)) {
        printf("Input is too large.\n");
        return;
    }

    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    for (i = 0; i < strlen(buffer); i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main() {
    char myInput[] = "abcdefghi"; // 9 characters
    readBuffer(myInput);
    return 0;
}