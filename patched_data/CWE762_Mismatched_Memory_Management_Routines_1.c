#include <stdlib.h>

int main() {
    char *buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }

    free(buffer);

    return 0;
}