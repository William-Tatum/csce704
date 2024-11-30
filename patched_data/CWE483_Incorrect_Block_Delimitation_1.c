#include <stdio.h>

void incorrectBlockDelimitation(int condition) {
    if (condition) {
        printf("Condition met\n");
        printf("This should only print if condition is met\n");
    }
    printf("This will always print\n");
}

int main() {
    incorrectBlockDelimitation(1);
    incorrectBlockDelimitation(0);
    return 0;
}