#include <stdio.h>
#include <wchar.h>

int main() {
    wchar_t multiByteStr[] = L"こんにちは";
    size_t length = wcslen(multiByteStr);
    printf("Length of the string: %zu\n", length);
    return 0;
}