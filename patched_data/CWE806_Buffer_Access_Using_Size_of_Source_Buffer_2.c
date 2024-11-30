#include <stdio.h>
#include <string.h>

void process_data(const char *source) {
    char dest[10];
    strncpy(dest, source, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';
    printf("Processed data: %s\n", dest);
}

int main() {
    char largeInput[] = "ThisInputIsTooLarge";
    process_data(largeInput);
    return 0;
}