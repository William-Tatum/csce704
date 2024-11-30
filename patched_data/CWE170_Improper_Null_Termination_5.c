#include <stdio.h>
#include <string.h>

void improper_null_termination() {
    char src[10] = "abcdefgh";
    char dest[8];
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';
    printf("Destination: %s\n", dest);
}

int main() {
    improper_null_termination();
    return 0;
}