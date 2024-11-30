#include <stdio.h>

void displayAge(int age) {
    printf("Age: %d\n", age);
}

int main() {
    int actualAge = 25;
    
    displayAge(actualAge);
    
    return 0;
}