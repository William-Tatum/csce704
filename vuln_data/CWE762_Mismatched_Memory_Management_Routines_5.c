#include <stdlib.h>

int main() {
    char *memory = (char *)malloc(100);
    if (memory == NULL) {
        return 1;
    }
    delete memory;
    return 0;
}