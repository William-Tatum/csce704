#include <stdio.h>
#include <string.h>

void printString(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    for (int i = 0; i < sizeof(buffer); i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main() {
    char safeInput[] = "HelloWorld";
    printString(safeInput);
    return 0;
}