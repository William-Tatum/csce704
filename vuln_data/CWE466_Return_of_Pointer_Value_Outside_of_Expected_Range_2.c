#include <stdio.h>
#include <stdlib.h>

char* get_message(int index) {
    static char messages[3][20] = {"Hello, World!", "Goodbye!", "Welcome!"};
    if (index < 0 || index >= 3) {
        return NULL;
    }
    return messages[index];
}

int main() {
    char *msg = get_message(5); // Vulnerable call with out-of-range index
    if (msg) {
        printf("%s\n", msg);
    } else {
        printf("Invalid index\n");
    }
    return 0;
}