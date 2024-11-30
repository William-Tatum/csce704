#include <string.h>
#include <stdio.h>

void copy_input(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char input_data[20];
    printf("Enter input data: ");
    fgets(input_data, sizeof(input_data), stdin);
    input_data[strcspn(input_data, "\n")] = '\0';
    copy_input(input_data);
    return 0;
}