#include <stdio.h>
#include <string.h>

void buffer_underwrite(char* input) {
    char buffer[10];
    if (input != NULL && strlen(input) < sizeof(buffer)) {
        strcpy(buffer, input);
        printf("Buffer contents: %s\n", buffer);
    } else {
        printf("Input is too large or null.\n");
    }
}

int main() {
    char* data = "testinput";
    buffer_underwrite(data);
    return 0;
}