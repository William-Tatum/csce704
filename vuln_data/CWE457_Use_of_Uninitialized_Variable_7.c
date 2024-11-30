#include <stdio.h>

void printUninitializedVariable() {
    int uninitializedVar;
    printf("Uninitialized Variable: %d\n", uninitializedVar);
}

int main() {
    printUninitializedVariable();
    return 0;
}