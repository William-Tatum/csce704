#include <stdio.h>
#include <string.h>

void appendToString(char *baseString, const char *toAppend, size_t maxLength) {
    size_t baseLength = strnlen(baseString, maxLength);
    size_t appendLength = strnlen(toAppend, maxLength);
    if (baseLength + appendLength + 1 > maxLength) return;
    strncat(baseString, toAppend, maxLength - baseLength - 1);
}

int main() {
    char str[10] = "Hello";

    appendToString(str, "!", sizeof(str) - strnlen(str, sizeof(str)) - 1);
    printf("%s\n", str);

    appendToString(str, "\0Extra", sizeof(str) - strnlen(str, sizeof(str)) - 1);
    printf("%s\n", str);

    appendToString(str, "CWE464", sizeof(str) - strnlen(str, sizeof(str)) - 1);
    printf("%s\n", str);

    return 0;
}