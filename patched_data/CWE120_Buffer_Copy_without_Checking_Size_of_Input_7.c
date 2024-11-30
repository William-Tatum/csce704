#include <string.h>
#include <stdio.h>

void copy_input(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char input_data[20];
    printf("Enter input data: ");
    if (fgets(input_data, sizeof(input_data), stdin) != NULL) {
        input_data[strcspn(input_data, "\n")] = '\0';
        copy_input(input_data);
    }
    return 0;
}