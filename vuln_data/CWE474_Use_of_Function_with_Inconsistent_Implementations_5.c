#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#define STRCMP _stricmp
#else
#define STRCMP strcasecmp
#endif

int main() {
    char str1[] = "Hello";
    char str2[] = "hello";

    if (STRCMP(str1, str2) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}