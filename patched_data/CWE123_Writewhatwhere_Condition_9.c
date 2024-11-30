#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    printf("Enter some input: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    printf("You entered: %s\n", buffer);
    return 0;
}