#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main() {
    const wchar_t *wideString = L"こんにちは";
    size_t incorrect_length = strlen((const char *)wideString);
    size_t correct_length = wcslen(wideString);

    printf("Incorrect Length: %zu\n", incorrect_length);
    printf("Correct Length: %zu\n", correct_length);

    return 0;
}