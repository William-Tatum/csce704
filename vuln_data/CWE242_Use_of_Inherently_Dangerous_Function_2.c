#include <stdio.h>
#include <string.h>

int main() {
    char buffer[32];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 1;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    printf("Input: %s\n", buffer);
    return 0;
}