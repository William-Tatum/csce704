#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer1 = malloc(100 * sizeof(char));
    char *buffer2 = malloc(100 * sizeof(char));

    if (buffer1 == NULL || buffer2 == NULL) {
        free(buffer1);
        free(buffer2);
        return 1;
    }

    char *p1 = buffer1 + 40;
    char *p2 = buffer2 + 60;

    ptrdiff_t diff = p2 - buffer2 + (buffer2 - buffer1) - (p1 - buffer1);

    printf("Difference: %td\n", diff);

    free(buffer1);
    free(buffer2);
    
    return 0;
}