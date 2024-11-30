#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main() {
    const char *multiByteString = "こんにちは"; // "Hello" in Japanese
    size_t incorrectLength = strlen(multiByteString);
    wchar_t wideString[100];
    mbstowcs(wideString, multiByteString, strlen(multiByteString) + 1);
    size_t correctLength = wcslen(wideString);
    printf("Incorrect Length: %zu\n", incorrectLength);
    printf("Correct Length: %zu\n", correctLength);
    return 0;
}