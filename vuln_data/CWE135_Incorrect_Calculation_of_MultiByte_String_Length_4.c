#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main() {
    wchar_t *multiByteString = L"こんにちは世界";
    size_t length;

    length = strlen((const char *)multiByteString);
    printf("Incorrect length calculation: %zu\n", length);

    length = wcslen(multiByteString);
    printf("Correct length calculation: %zu\n", length);

    return 0;
}