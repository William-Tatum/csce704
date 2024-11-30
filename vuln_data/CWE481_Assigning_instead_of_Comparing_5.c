#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    // Mistaken assignment instead of comparison
    if (a = b) {
        printf("This will always print because a = b evaluates to non-zero.\n");
    } else {
        printf("This will never print.\n");
    }

    return 0;
}