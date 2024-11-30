#include <stdio.h>
#include <string.h>

int main() {
    char input_buffer[50];
    char output_buffer[50];
    printf("Enter some text: ");
    if (fgets(input_buffer, sizeof(input_buffer), stdin)) {
        input_buffer[strcspn(input_buffer, "\n")] = '\0';
        strncpy(output_buffer, input_buffer, sizeof(output_buffer) - 1);
        output_buffer[sizeof(output_buffer) - 1] = '\0';
        printf("Output: %s\n", output_buffer);
    }
    return 0;
}