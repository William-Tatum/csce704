#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    gets(buffer);

    char another_buffer[10];
    scanf("%s", another_buffer);

    printf("Buffer: %s\n", buffer);
    printf("Another Buffer: %s\n", another_buffer);

    return 0;
}