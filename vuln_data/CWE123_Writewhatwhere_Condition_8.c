#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    void (*functionPointer)();
    void maliciousFunction() {
        printf("Malicious code executed!\n");
    }
    functionPointer = NULL;
    printf("Enter data: ");
    gets(buffer);
    if (functionPointer) {
        functionPointer();
    }
    return 0;
}