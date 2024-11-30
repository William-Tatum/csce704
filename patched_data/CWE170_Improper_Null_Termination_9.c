#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "This is a long string that could cause an overflow if not handled properly";
    char destination[20];
    
    strncpy(destination, source, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';
    
    printf("Destination: %s\n", destination);
    return 0;
}