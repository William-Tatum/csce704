#include <stdio.h>
#include <string.h>

void print_os_dependent_behavior(const char *message) {
    int result;
    #ifdef _WIN32
        result = stricmp(message, "example");
    #elif defined(__linux__)
        result = strcasecmp(message, "example");
    #else
        printf("Unsupported platform\n");
        return;
    #endif
    if (result == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are different\n");
    }
}

int main() {
    print_os_dependent_behavior("Example");
    return 0;
}