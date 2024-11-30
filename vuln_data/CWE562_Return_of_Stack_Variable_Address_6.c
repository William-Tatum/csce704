#include <stdio.h>

char* getStackVariable() {
    char localVar[10] = "Hello";
    return localVar;
}

int main() {
    char* str = getStackVariable();
    printf("String: %s\n", str);
    return 0;
}