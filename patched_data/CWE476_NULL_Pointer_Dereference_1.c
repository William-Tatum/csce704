#include <stdio.h>
#include <string.h>

void printLength(char *str) {
    if (str == NULL) {
        printf("Invalid string input.\n");
        return;
    }
    printf("Length of the string is: %zu\n", strlen(str));
}

int main() {
    char *text = "Example string";
    printLength(text);
    return 0;
}