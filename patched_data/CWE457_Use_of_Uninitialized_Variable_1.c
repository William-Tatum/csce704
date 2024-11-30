#include <stdio.h>

int main() {
    int uninitializedVar = 0;
    if (uninitializedVar > 0) {
        printf("The variable is positive.\n");
    } else {
        printf("The variable is non-positive.\n");
    }
    return 0;
}