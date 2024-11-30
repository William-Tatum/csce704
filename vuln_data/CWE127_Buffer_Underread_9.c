#include <stdio.h>
#include <string.h>

void printData(const char *buffer, size_t size) {
    if (size == 0) return;
    for (size_t i = 0; i < size; ++i) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main() {
    const char validData[] = "SensitiveData";
    size_t validSize = sizeof(validData) / sizeof(validData[0]);

    size_t dangerousIndex = -5; 
    if (dangerousIndex < 0 || dangerousIndex >= validSize) {
        printf("Invalid index access attempt\n");
        return 1;
    }

    printData(validData + dangerousIndex, validSize - dangerousIndex);
    return 0;
}