#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *data = "This is a long string that will overflow the buffer";
    strcpy(buffer, data); // This line causes out-of-bounds write
    printf("%s\n", buffer);
    return 0;
}