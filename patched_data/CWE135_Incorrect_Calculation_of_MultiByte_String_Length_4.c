#include <stdio.h>
#include <wchar.h>

int main() {
    wchar_t *multiByteString = L"こんにちは世界";
    size_t length;

    length = wcslen(multiByteString);
    printf("Correct length calculation: %zu\n", length);

    return 0;
}