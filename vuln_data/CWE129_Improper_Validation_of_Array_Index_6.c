#include <stdio.h>

int main() {
    int data;
    int array[10];
    
    printf("Enter an index: ");
    scanf("%d", &data);
    
    if (data >= 0 && data < 10) {
        array[data] = 1; // Accessing the array safely
        printf("Accessed array[%d]\n", data);
    } else {
        printf("Invalid index!\n");
    }
    
    return 0;
}