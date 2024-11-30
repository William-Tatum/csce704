#include <stdio.h>
#include <string.h>

void safeStringCopy(char *dest, const char *src, size_t size) {
    if (size > 0) {
        strncpy(dest, src, size - 1);
        dest[size - 1] = '\0';
    }
}

int main() {
    char userInput[10];
    char secureBuffer[10];

    printf("Enter some text: ");
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        safeStringCopy(secureBuffer, userInput, sizeof(secureBuffer));
        printf("Secure Buffer contains: %s\n", secureBuffer);
    }

    return 0;
}