#include <stdio.h>
#include <string.h>

int main() {
    char buffer[32];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 1;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    if (strncmp(buffer, "Input: ", 7) != 0) {
        printf("Input: %s\n", buffer);
    } else {
        printf("Invalid input.\n");
        return 1;
    }
    return 0;
}