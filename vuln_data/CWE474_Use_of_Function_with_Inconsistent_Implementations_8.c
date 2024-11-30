#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[50];
    printf("Enter a file path: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char command[100];
#ifdef _WIN32
        snprintf(command, sizeof(command), "type %s", input);
#else
        snprintf(command, sizeof(command), "cat %s", input);
#endif
        if (system(command) < 0) {
            fprintf(stderr, "Command execution failed.\n");
        }
    } else {
        fprintf(stderr, "Input error.\n");
    }
    return 0;
}