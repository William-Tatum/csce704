#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *data = "This is a long string that exceeds the buffer size.";
    int i;
    
    for (i = 0; i <= strlen(data); i++) {
        buffer[i] = data[i];
    }

    printf("Buffer content: %s\n", buffer);
    return 0;
}