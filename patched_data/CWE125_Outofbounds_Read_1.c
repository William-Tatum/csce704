#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strncpy(buffer, "Hell", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Accessing buffer safely: %c\n", buffer[9]);
    return 0;
}