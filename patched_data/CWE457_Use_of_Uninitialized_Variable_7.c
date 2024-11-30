#include <stdio.h>

void printInitializedVariable() {
    int initializedVar = 0;
    printf("Initialized Variable: %d\n", initializedVar);
}

int main() {
    printInitializedVariable();
    return 0;
}