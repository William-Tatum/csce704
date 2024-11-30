#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *data = malloc(5);
    if (data == NULL) {
        return 1;
    }
    strncpy(data, "123", 4);
    data[4] = '\0';

    int intValue;
    if (sscanf(data, "%d", &intValue) == 1) {
        printf("Interpreted as int: %d\n", intValue);
    } else {
        printf("Failed to parse integer\n");
    }

    free(data);
    return 0;
}