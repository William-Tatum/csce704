#include <stdlib.h>

int main() {
    char *buffer;

    buffer = (char *)malloc(100);
    if (buffer == NULL) {
        return 1;
    }

    // Incorrect deallocation using `delete` which is for C++
    // This will cause undefined behavior
    delete buffer;

    return 0;
}