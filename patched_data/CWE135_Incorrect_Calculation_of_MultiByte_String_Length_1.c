#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void printStringLength(char *input) {
    size_t length = strlen(input);
    printf("Length of string (in bytes): %zu\n", length);
}

void printWideStringLength(wchar_t *input) {
    size_t length = wcslen(input);
    printf("Length of wide string (in characters): %zu\n", length);
}

int main() {
    setlocale(LC_ALL, "");
    char multiByteStr[] = "こんにちは"; // Multibyte string (UTF-8)
    wchar_t wideStr[] = L"こんにちは"; // Wide string

    printStringLength(multiByteStr);
    printWideStringLength(wideStr);

    return 0;
}