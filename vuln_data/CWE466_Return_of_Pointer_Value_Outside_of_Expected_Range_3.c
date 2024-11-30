#include <stdio.h>
#include <stdlib.h>

char* getSubstring(char* str, int start, int length) {
    if (start < 0 || length <= 0 || start >= strlen(str)) return NULL;
    return str + start + length; 
}

int main() {
    char buffer[] = "CWE-466 Example";
    char* result = getSubstring(buffer, 5, 20);
    if (result != NULL) {
        printf("Substring: %s\n", result);
    } else {
        printf("Invalid range\n");
    }
    return 0;
}