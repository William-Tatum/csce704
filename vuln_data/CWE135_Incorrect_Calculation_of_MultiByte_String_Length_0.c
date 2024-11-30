#include <stdio.h>
#include <string.h>
#include <wchar.h>

void incorrectLengthCalculation(const wchar_t *input) {
    size_t byteLength = strlen((const char *)input);
    printf("Calculated byte length: %zu (incorrect for wide characters)\n", byteLength);
}

int main() {
    wchar_t wideString[] = L"こんにちは";
    incorrectLengthCalculation(wideString);
    return 0;
}