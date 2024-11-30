#include <stdio.h>
#include <string.h>

void fixed_function() {
    char buffer[10];
    strncpy(buffer, "SensitiveData123", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    
    for(int i = 0; i < sizeof(buffer); i++) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    fixed_function();
    return 0;
}