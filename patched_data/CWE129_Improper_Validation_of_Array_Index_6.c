#include <stdio.h>

int main() {
    int data;
    int array[10];
    
    printf("Enter an index: ");
    if (scanf("%d", &data) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    
    if (data >= 0 && data < 10) {
        array[data] = 1; 
        printf("Accessed array[%d]\n", data);
    } else {
        printf("Invalid index!\n");
    }
    
    return 0;
}