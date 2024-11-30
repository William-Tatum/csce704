#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main() {
    char multiByteStr[] = "こんにちは"; // "Hello" in Japanese
    int incorrectLength = strlen(multiByteStr);
    wchar_t wideStr[] = L"こんにちは";
    int correctLength = wcslen(wideStr);
    printf("Incorrect length: %d\n", incorrectLength);
    printf("Correct length: %d\n", correctLength);
    return 0;
}