#include <stdio.h>
#include <string.h>

void vulnerable_function() {
    char buffer[10];
    strncpy(buffer, "SensitiveData123", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    
    for(int i = 0; i <= 15; i++) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    vulnerable_function();
    return 0;
}