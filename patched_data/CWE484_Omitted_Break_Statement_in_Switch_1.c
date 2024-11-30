#include <stdio.h>

int main() {
    int testValue = 2;

    switch(testValue) {
        case 1:
            printf("Case 1 executed.\n");
            break;
        case 2:
            printf("Case 2 executed.\n");
            break;
        case 3:
            printf("Case 3 executed.\n");
            break;
        case 4:
            printf("Case 4 executed.\n");
            break;
        default:
            printf("Default executed.\n");
            break;
    }

    return 0;
}