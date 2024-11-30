#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* riskyFunction() {
    if (rand() % 2 == 0) {
        return NULL;
    }
    return "Success";
}

int main() {
    srand((unsigned int)time(NULL));
    const char *result = riskyFunction();
    if (result == NULL) {
        fprintf(stderr, "Error: Function returned NULL\n");
        return 1;
    }
    printf("Function returned: %s\n", result);
    return 0;
}