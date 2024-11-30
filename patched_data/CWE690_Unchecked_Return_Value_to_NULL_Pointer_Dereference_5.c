#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(const char *data) {
    if (data == NULL) {
        printf("No data to process\n");
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
    
    strncpy(data, "Important Data", 19);
    data[19] = '\0';
    process_data(data);
    
    free(data);
    return 0;
}