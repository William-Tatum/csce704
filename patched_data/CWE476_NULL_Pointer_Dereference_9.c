#include <stdio.h>

void printStringLength(const char *str) {
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
    const char *text = "Sample text";
    printStringLength(text);
    return 0;
}