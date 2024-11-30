#include <stdio.h>

int main() {
    unsigned char value = 250;
    for (int i = 0; i < 10; i++) {
        if (value < 255) {
            value++;
        }
        printf("Value: %u\n", value);
    }
    return 0;
}