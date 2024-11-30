#include <string.h>
#include <stdio.h>

void vulnerable_function(char *input) {
    char buffer[10];
    strcpy(buffer, input);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        vulnerable_function(argv[1]);
        printf("Buffer overflow attack executed!\n");
    } else {
        printf("Usage: %s <input>\n", argv[0]);
    }
    return 0;
}