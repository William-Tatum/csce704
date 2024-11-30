#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>

int main() {
    char *multiByteString = "Привет, мир"; // Wide characters in UTF-8 encoding
    size_t length;

    length = strlen(multiByteString); // Incorrect length calculation for multi-byte string

    printf("The length of the multi-byte string is: %zu\n", length);

    return 0;
}