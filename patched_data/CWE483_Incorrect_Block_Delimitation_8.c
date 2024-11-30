#include <stdio.h>

int main() {
    int condition = 1;
    int importantVariable = 0;
    
    if (condition) {
        importantVariable = 1;
        importantVariable += 2;
    }
    
    if (importantVariable == 3) {
        printf("Success: Condition met\n");
    } else {
        printf("Error: Condition not met\n");
    }

    return 0;
}