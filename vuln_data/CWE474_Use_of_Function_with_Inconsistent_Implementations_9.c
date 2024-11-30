#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#define STRCASECMP _stricmp
#elif defined(__linux__) || defined(__APPLE__)
#define STRCASECMP strcasecmp
#else
#error "Platform not supported"
#endif

int main() {
    char str1[] = "Hello";
    char str2[] = "hello";

    if (STRCASECMP(str1, str2) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    return 0;
}