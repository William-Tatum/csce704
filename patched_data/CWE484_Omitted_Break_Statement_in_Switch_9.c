#include <stdio.h>

int main() {
    int option = 2;
    
    switch (option) {
        case 1:
            printf("Option 1 selected.\n");
            break;
        case 2:
            printf("Option 2 selected.\n");
            break;
        case 3:
            printf("Option 3 also executed due to missing break.\n");
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}