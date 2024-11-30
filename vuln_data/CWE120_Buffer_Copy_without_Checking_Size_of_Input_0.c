#include <stdio.h>
#include <string.h>

int main() {
    char input_buffer[50];
    char output_buffer[50];
    printf("Enter some text: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    strcpy(output_buffer, input_buffer);
    printf("Output: %s\n", output_buffer);
    return 0;
}