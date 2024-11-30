#include <stdio.h>
#include <string.h>

int main() {
    char buffer[50];
    printf("Enter your name: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("Hello, %s", buffer);
    }
    return 0;
}