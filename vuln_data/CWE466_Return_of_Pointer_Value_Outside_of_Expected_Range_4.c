#include <stdio.h>

char* get_substring(char* str, int start, int length) {
    if (start < 0 || length < 0) {
        return NULL;
    }
    return &str[start];
}

int main() {
    char buffer[] = "This is a test string.";
    char *result = get_substring(buffer, 5, 10);
    if (result != NULL) {
        printf("Substring: %s\n", result);
    } else {
        printf("Invalid range.\n");
    }
    return 0;
}