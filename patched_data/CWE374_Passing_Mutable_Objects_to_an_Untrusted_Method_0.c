#include <stdio.h>
#include <string.h>

void untrusted_function(char *data, size_t size) {
    strncpy(data, "Data altered by untrusted function", size - 1);
    data[size - 1] = '\0'; // Ensure null termination
}

int main() {
    char original_data[50] = "Original data";
    char cloned_data[50];

    strncpy(cloned_data, original_data, sizeof(cloned_data) - 1);
    cloned_data[sizeof(cloned_data) - 1] = '\0'; // Ensure null termination

    untrusted_function(cloned_data, sizeof(cloned_data));

    printf("Original Data: %s\n", original_data);
    printf("Cloned Data: %s\n", cloned_data);

    return 0;
}