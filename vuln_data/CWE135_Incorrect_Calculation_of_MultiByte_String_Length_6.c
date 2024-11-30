#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main() {
    wchar_t multiByteStr[] = L"こんにちは"; // Wide multi-byte string
    size_t length = strlen((char*)multiByteStr); // Incorrect length calculation
    printf("Length of the string: %zu\n", length);
    return 0;
}