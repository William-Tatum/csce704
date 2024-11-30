#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    wchar_t multiByteStr[] = L"こんにちは"; // "Hello" in Japanese
    int correctLength = wcslen(multiByteStr);
    printf("Correct length: %d\n", correctLength);
    return 0;
}