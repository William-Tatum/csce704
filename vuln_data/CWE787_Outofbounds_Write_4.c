#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    int index;
    printf("Enter index to write data (0-9): ");
    scanf("%d", &index);
    if (index >= 0 && index < 10) {
        buffer[index] = 'A';
        printf("Data written at index %d\n", index);
    } else {
        printf("Error: Index out of bounds\n");
    }
    return 0;
}