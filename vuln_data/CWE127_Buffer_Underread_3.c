#include <stdio.h>
#include <string.h>

void buffer_underread() {
    char sensitive_data[] = "SensitiveData";
    char buffer[16];
    char *pointer;

    strcpy(buffer, "Hello, World!");

    pointer = buffer; 
    pointer -= 5; 

    for (int i = 0; i < 16; i++) {
        printf("%c", *(pointer + i));
    }
}

int main() {
    buffer_underread();
    return 0;
}