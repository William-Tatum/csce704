#include <stdio.h>
#include <string.h>

void unsafe(char *input) {
    char buffer[10];
    unsigned *ptr;
    if (strlen(input) > 10) {
        ptr = (unsigned *)(buffer + 20);
        *ptr = 0xDEADBEEF;
    }
    strcpy(buffer, input);
    printf("Buffer: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        unsafe(argv[1]);
    } else {
        printf("Please provide an input.\n");
    }
    return 0;
}