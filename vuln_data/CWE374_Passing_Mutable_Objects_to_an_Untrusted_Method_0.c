#include <stdio.h>
#include <string.h>

void untrusted_function(char *data) {
    strcpy(data, "Data altered by untrusted function");
}

int main() {
    char original_data[50] = "Original data";
    char cloned_data[50];

    strcpy(cloned_data, original_data);

    untrusted_function(cloned_data);

    printf("Original Data: %s\n", original_data);
    printf("Cloned Data: %s\n", cloned_data);

    return 0;
}