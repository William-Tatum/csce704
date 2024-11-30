#include <stdio.h>

void printStringLength(char *str) {
    int length = 0;
    if (str == NULL) {
        printf("Error: Attempted to dereference a NULL pointer.\n");
        return;
    }
    while (str[length] != '\0') {
        length++;
    }
    printf("String length: %d\n", length);
}

int main() {
    char *text = NULL;
    printStringLength(text);
    return 0;
}