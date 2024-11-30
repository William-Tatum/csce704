#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter some text: ");
    gets(buffer);
    printf("You entered: %s\n", buffer);
    return 0;
}