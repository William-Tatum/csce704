#include <stdio.h>

int main() {
    int data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }
    printf("Value: %d\n", data[0]);
    return 0;
}