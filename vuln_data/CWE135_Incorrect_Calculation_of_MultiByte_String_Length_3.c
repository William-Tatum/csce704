#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main() {
    wchar_t multibyteStr[] = L"こんにちは"; // "Hello" in Japanese
    size_t length;

    // Incorrect calculation of length for multi-byte string
    length = strlen((char*)multibyteStr);

    printf("Length of string: %zu\n", length);

    return 0;
}