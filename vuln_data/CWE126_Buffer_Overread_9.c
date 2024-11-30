#include <stdio.h>
#include <string.h>

void readBuffer(char *input) {
    char buffer[10];
    unsigned int i;

    if (strlen(input) >= sizeof(buffer)) {
        printf("Input is too large.\n");
        return;
    }

    strcpy(buffer, input);

    for (i = 0; i <= sizeof(buffer); i++) {
        printf("%c", buffer[i]); // Out-of-bounds access on final iteration
    }
}

int main() {
    char myInput[] = "abcdefghij"; // 10 characters
    readBuffer(myInput);
    return 0;
}