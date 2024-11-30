#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_substring(char* str, int start, int length) {
    int str_length = strlen(str);
    
    if (start < 0 || length < 0 || start >= str_length || start + length > str_length) {
        return NULL;
    }
    
    char *substr = (char *)malloc((length + 1) * sizeof(char));
    if (!substr) {
        return NULL;
    }
    
    strncpy(substr, str + start, length);
    substr[length] = '\0';
    return substr;
}

int main() {
    char buffer[] = "This is a test string.";
    
    int start = 5, length = 10;
    char *result = get_substring(buffer, start, length);
    
    if (result != NULL) {
        printf("Substring: %s\n", result);
        free(result);
    } else {
        printf("Invalid range.\n");
    }
    
    return 0;
}