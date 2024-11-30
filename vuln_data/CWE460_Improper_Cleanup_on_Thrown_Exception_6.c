#include <stdio.h>
#include <stdlib.h>
int process_data(int data) {
    char *buffer = (char *)malloc(1024);
    if (!buffer) return -1;
    if (data < 0) {
        free(buffer);
        return -1;
    }
    if (data > 1000) {
        // Forgetting to free buffer on this early return
        return -1;
    }
    // Process data
    free(buffer);
    return 0;
}
int main() {
    int result = process_data(1500);
    if (result == -1) {
        printf("Error processing data\n");
    } else {
        printf("Data processed successfully\n");
    }
    return 0;
}