#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(char *data) {
    if (data == NULL) {
        printf("Failed to allocate memory\n");
        return;
    }
    printf("Processing: %s\n", data);
}

int main() {
    char *data = (char *)malloc(20 * sizeof(char));
    if (data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    strcpy(data, "Important Data");
    process_data(data);
    
    free(data);
    return 0;
}