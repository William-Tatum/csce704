#include <stdio.h>
#include <string.h>

void printString(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    for (int i = 0; i <= 10; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main() {
    char safeInput[] = "HelloWorld";
    printString(safeInput);
    return 0;
}