#include <stdio.h>

void processNumber(short input) {
    unsigned long extendedInput;
    
    if (input < 0) {
        printf("Error: Negative input\n");
        return;
    }

    extendedInput = (unsigned long)input;
    printf("Processed number: %lu\n", extendedInput);
}

int main() {
    short num;

    printf("Enter a number: ");
    scanf("%hd", &num);

    processNumber(num);

    return 0;
}