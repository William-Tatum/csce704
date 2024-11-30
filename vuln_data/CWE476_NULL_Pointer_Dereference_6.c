#include <stdio.h>
#include <stdlib.h>

void printMessage(char *message) {
    printf("%s\n", message);
}

int main() {
    char *ptr = NULL;
    if (ptr != NULL) {
        printMessage(ptr);
    } else {
        printf("Pointer is NULL, cannot dereference.\n");
    }
    return 0;
}