#include <stdio.h>
#include <stdlib.h>

void double_free_example() {
    char *buffer = malloc(100);
    if (buffer == NULL) {
        return;
    }

    free(buffer);

    // Double free vulnerability
    free(buffer);
}

int main() {
    double_free_example();
    return 0;
}