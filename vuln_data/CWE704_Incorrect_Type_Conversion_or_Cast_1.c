#include <stdio.h>

void process(int value) {
    printf("Processed value: %d\n", value);
}

int main() {
    double input = 42.56;
    process((int)input);
    return 0;
}