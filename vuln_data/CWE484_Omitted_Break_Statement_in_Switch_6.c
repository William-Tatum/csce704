#include <stdio.h>

void checkNumber(int num) {
    switch(num) {
        case 1:
            printf("Number is One\n");
        case 2:
            printf("Number is Two\n");
        case 3:
            printf("Number is Three\n");
        default:
            printf("Number is Unknown\n");
    }
}

int main() {
    checkNumber(2);
    return 0;
}