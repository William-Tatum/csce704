#include <stdio.h>
#include <string.h>
#include <wchar.h>

void printStringLength(char *input) {
    printf("Length of string: %zu\n", strlen(input));
}

void printWideStringLength(wchar_t *input) {
    printf("Length of wide string: %zu\n", wcslen(input));
}

int main() {
    char multiByteStr[] = "こんにちは"; // Multibyte string (UTF-8)
    wchar_t wideStr[] = L"こんにちは"; // Wide string

    printStringLength(multiByteStr);
    printWideStringLength(wideStr);

    return 0;
}