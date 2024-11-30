#include <stdio.h>
#include <string.h>

void process_data(const char *source) {
    char dest[10];
    if (strlen(source) >= sizeof(dest)) {
        fprintf(stderr, "Source is too large for destination buffer.\n");
        return;
    }
    strcpy(dest, source);
    printf("Processed data: %s\n", dest);
}

int main() {
    char largeInput[] = "ThisInputIsTooLarge";
    process_data(largeInput);
    return 0;
}