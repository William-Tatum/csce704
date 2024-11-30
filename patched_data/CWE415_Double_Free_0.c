#include <stdlib.h>
#include <stdio.h>

int main() {
    char *data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) {
        return 1;
    }
    free(data);
    data = NULL;
    return 0;
}