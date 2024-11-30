#include <stdio.h>

void printLength(char *str) {
    printf("Length of the string is: %zu\n", strlen(str));
}

int main() {
    char *text = NULL;
    printLength(text);
    return 0;
}