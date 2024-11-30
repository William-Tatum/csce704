#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter some text: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character if present
    printf("You entered: %s\n", buffer);
    return 0;
}