#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[8];
    strcpy(buffer, input);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        vulnerable_function(argv[1]);
    }
    return 0;
}