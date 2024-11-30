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
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Removing trailing newline if exists
    }
    if (functionPointer) {
        functionPointer();
    }
    return 0;
}