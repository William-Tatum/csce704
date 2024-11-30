#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character if present
        printf("You entered: %s\n", buffer);
    }
    return 0;
}