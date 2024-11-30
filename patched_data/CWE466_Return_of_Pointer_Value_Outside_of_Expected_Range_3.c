#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getSubstring(char* str, int start, int length) {
    int str_len = strlen(str);
    if (start < 0 || length <= 0 || start >= str_len || start + length > str_len) return NULL;

    char* substr = (char*)malloc((length + 1) * sizeof(char));
    if (substr == NULL) return NULL;

    strncpy(substr, str + start, length);
    substr[length] = '\0';
    return substr;
}

int main() {
    char buffer[] = "CWE-466 Example";
    char* result = getSubstring(buffer, 5, 7);
    if (result != NULL) {
        printf("Substring: %s\n", result);
        free(result);
    } else {
        printf("Invalid range\n");
    }
    return 0;
}