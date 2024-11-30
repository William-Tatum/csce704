#include <stdio.h>
#include <wchar.h>

void correctLengthCalculation(const wchar_t *input) {
    size_t length = wcslen(input);
    printf("Calculated length of wide characters: %zu\n", length);
}

int main() {
    wchar_t wideString[] = L"こんにちは";
    correctLengthCalculation(wideString);
    return 0;
}