#include <stdio.h>
#include <string.h>

void appendToString(char *baseString, const char *toAppend, size_t maxLength) {
    size_t baseLength = strlen(baseString);
    size_t appendLength = strlen(toAppend);
    if (baseLength + appendLength + 1 > maxLength) return;
    strncat(baseString, toAppend, maxLength - baseLength - 1);
}

int main() {
    char str[10] = "Hello";

    appendToString(str, "!", sizeof(str));
    printf("%s\n", str);

    appendToString(str, "\0Extra", sizeof(str));
    printf("%s\n", str);

    appendToString(str, "CWE464", sizeof(str));
    printf("%s\n", str);

    return 0;
}