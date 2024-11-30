#include <stdio.h>

int main() {
    unsigned char value = 250;
    for (int i = 0; i < 10; i++) {
        value++;
        printf("Value: %u\n", value);
    }
    return 0;
}