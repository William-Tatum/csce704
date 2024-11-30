#include <stdio.h>

void checkAndPrint(int condition) {
    if (condition)
        printf("Condition is true.\n");
        printf("This statement should only print if the condition is true.\n");
}

int main() {
    checkAndPrint(1); // This will print both statements
    checkAndPrint(0); // This will incorrectly print the second statement
    return 0;
}