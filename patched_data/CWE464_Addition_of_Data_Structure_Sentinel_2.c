#include <stdio.h>
#include <string.h>

void appendString(char *original, const char *addition, size_t maxSize) {
    size_t originalLen = strlen(original);
    size_t additionLen = strlen(addition);
    
    if (originalLen >= maxSize - 1) {
        printf("Error: No space left to append\n");
        return;
    }
    
    size_t spaceLeft = maxSize - originalLen - 1;
    size_t toCopy = (additionLen < spaceLeft) ? additionLen : spaceLeft;
    
    for (size_t i = 0; i < toCopy; i++) {
        original[originalLen + i] = addition[i];
    }
    
    original[originalLen + toCopy] = '\0';
}

int main() {
    char buffer[10] = "Test";
    char *dataToAppend = "1234567";
    
    appendString(buffer, dataToAppend, sizeof(buffer));
    printf("Resulting string: %s\n", buffer);
    
    return 0;
}