#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getStackVariable() {
    char* localVar = malloc(10 * sizeof(char));
    if (localVar == NULL) {
        return NULL;
    }
    strcpy(localVar, "Hello");
    return localVar;
}

int main() {
    char* str = getStackVariable();
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("String: %s\n", str);
    free(str);
    return 0;
}