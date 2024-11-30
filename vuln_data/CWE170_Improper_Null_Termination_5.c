#include <stdio.h>
#include <string.h>

void improper_null_termination() {
    char src[10] = "abcdefgh";
    char dest[8];
    strncpy(dest, src, sizeof(dest) - 1);
    // Improperly null-terminated, could lead to undefined behavior
    printf("Destination: %s\n", dest);
}

int main() {
    improper_null_termination();
    return 0;
}