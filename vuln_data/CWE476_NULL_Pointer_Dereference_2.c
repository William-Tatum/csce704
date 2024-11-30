#include <stdio.h>
#include <stdlib.h>

void printMessage(char *message) {
    printf("%s\n", message);
}

int main() {
    char *text = NULL;
    printMessage(text);
    return 0;
}