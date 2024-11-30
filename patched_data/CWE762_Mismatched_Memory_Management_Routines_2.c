#include <stdlib.h>

int main() {
    char *buffer;

    buffer = (char *)malloc(100);
    if (buffer == NULL) {
        return 1;
    }

    free(buffer);

    return 0;
}