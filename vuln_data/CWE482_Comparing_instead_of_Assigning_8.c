int main() {
    int value = 0;
    int number = 10;
    
    // Error: Using comparison instead of assignment
    if (value == number) {
        printf("Value is assigned the number.\n");
    }
    
    // Correct: Using assignment
    value = number;
    
    if (value == number) {
        printf("Value is equal to number now.\n");
    }
    
    return 0;
}