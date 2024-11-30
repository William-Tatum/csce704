#include <stdio.h>
#include <wchar.h>

int main() {
    wchar_t multibyteStr[] = L"こんにちは"; // "Hello" in Japanese
    size_t length;

    length = wcslen(multibyteStr);

    printf("Length of string: %zu\n", length);

    return 0;
}