#include <stdio.h>

void processNumber(short input) {
    if (input >= 0 && input < 1024) {
        printf("Value is within expected range: %d\n", input);
    } else {
        printf("Value exceeds expected range or is negative: %d\n", input);
    }
}

int main() {
    short num = -1;
    processNumber(num);
    return 0;
}