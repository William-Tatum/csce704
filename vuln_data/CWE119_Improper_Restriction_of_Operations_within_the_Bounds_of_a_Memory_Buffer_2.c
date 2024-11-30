#include <stdio.h>
#include <string.h>

void unsafeFunction(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char data[] = "ThisStringIsWayTooLong";
    unsafeFunction(data);
    return 0;
}