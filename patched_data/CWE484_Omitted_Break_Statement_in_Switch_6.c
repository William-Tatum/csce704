#include <stdio.h>

void checkNumber(int num) {
    switch(num) {
        case 1:
            printf("Number is One\n");
            break;
        case 2:
            printf("Number is Two\n");
            break;
        case 3:
            printf("Number is Three\n");
            break;
        default:
            printf("Number is Unknown\n");
            break;
    }
}

int main() {
    checkNumber(2);
    return 0;
}