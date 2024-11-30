#include <stdio.h>
#include <math.h>

int main() {
    double large_number = 1.999999;
    int correct_round = (int)round(large_number);
    printf("Correctly rounded number: %d\n", correct_round);
    return 0;
}