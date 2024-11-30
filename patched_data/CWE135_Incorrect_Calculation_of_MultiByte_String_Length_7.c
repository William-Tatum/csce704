#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); // Set the locale for wide characters

    wchar_t *wideString = L"Привет, мир"; // Wide characters in wide string
    size_t length;

    length = wcslen(wideString); // Correct length calculation for wide string

    printf("The length of the wide string is: %zu\n", length);

    return 0;
}