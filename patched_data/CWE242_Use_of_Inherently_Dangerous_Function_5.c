#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    char another_buffer[10];
    scanf("%9s", another_buffer);

    printf("Buffer: %s\n", buffer);
    printf("Another Buffer: %s\n", another_buffer);

    return 0;
}