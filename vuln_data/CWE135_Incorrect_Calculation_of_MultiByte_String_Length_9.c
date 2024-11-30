#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main() {
    setlocale(LC_ALL, "");

    wchar_t wide_str[] = L"こんにちは"; 
    char multi_byte_str[256]; 

    wcstombs(multi_byte_str, wide_str, sizeof(multi_byte_str));

    size_t length_incorrect = strlen(multi_byte_str);
    size_t length_correct = wcslen(wide_str);

    printf("Incorrect length: %zu\n", length_incorrect);
    printf("Correct length: %zu\n", length_correct);

    return 0; 
}