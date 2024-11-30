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
    int index;
    printf("Enter a message index (0-2): ");
    if (scanf("%d", &index) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    char *msg = get_message(index);
    if (msg) {
        printf("%s\n", msg);
    } else {
        printf("Invalid index\n");
    }
    return 0;
}