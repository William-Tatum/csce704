#include <stdio.h>

void display(int num) {
    printf("Number: %d\n", num);
}

int main() {
    int a = 10;
    display(a, 20); // Incorrect number of arguments
    return 0;
}