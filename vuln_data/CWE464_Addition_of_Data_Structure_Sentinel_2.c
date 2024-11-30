#include <stdio.h>
#include <string.h>

void appendString(char *original, const char *addition, size_t maxSize) {
    size_t originalLen = strlen(original);
    size_t additionLen = strlen(addition);
    
    if (originalLen + additionLen + 1 > maxSize) {
        printf("Error: String too large to append\n");
        return;
    }
    
    for (size_t i = 0; i < additionLen; i++) {
        original[originalLen + i] = addition[i];
    }
    
    original[originalLen + additionLen] = '\0';
}

int main() {
    char buffer[10] = "Test";
    char *dataToAppend = "1234567";
    
    appendString(buffer, dataToAppend, sizeof(buffer));
    printf("Resulting string: %s\n", buffer);
    
    return 0;
}