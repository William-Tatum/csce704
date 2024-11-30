#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 256

void process_data(const char *data, size_t reported_length) {
    if (reported_length >= BUF_SIZE) {
        printf("Reported length exceeds buffer size.\n");
        return;
    }
    
    if (strnlen(data, BUF_SIZE) != reported_length) {
        printf("Length parameter inconsistency detected!\n");
        return;
    }
    
    char buffer[BUF_SIZE];
    memcpy(buffer, data, reported_length);
    buffer[reported_length] = '\0';
    
    printf("Processed data: %s\n", buffer);
}

int main() {
    const char *user_input = "Example input";
    size_t input_length = 13;
    
    process_data(user_input, input_length);
    
    return 0;
}