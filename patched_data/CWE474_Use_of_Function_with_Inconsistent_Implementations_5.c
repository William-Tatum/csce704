#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <ctype.h>
int secure_stricmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && tolower((unsigned char)*s1) == tolower((unsigned char)*s2)) {
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}
#define STRCMP secure_stricmp
#else
#define STRCMP strcasecmp
#endif

int main() {
    const char *str1 = "Hello";
    const char *str2 = "hello";

    if (STRCMP(str1, str2) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}