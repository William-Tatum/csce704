#include <stdio.h>

void displayAge(int age) {
    printf("Age: %d\n", age);
}

int main() {
    int actualAge = 25;
    float incorrectAge = 25.0;
    
    displayAge(incorrectAge);
    
    return 0;
}