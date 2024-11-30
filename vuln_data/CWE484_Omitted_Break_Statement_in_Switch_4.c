#include <stdio.h>

void exampleFunction(int number) {
    switch (number) {
        case 1:
            printf("Case 1\n");
            // Note: Missing break statement here
        case 2:
            printf("Case 2\n");
            break;
        case 3:
            printf("Case 3\n");
            break;
        default:
            printf("Default case\n");
            break;
    }
}

int main() {
    exampleFunction(1);
    return 0;
}