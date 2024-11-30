#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 10

void copy_data(const char* src, size_t length) {
    char destination[BUFFER_SIZE];
    size_t bytes_to_copy = length < BUFFER_SIZE ? length : BUFFER_SIZE - 1;
    memcpy(destination, src, bytes_to_copy);
    destination[bytes_to_copy] = '\0';
    printf("Data copied: %s\n", destination);
}

int main() {
    const char* source = "This is a long string that will cause an overflow";
    size_t length_to_copy = 20;
    copy_data(source, length_to_copy);
    return 0;
}