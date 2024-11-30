#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char buffer[64];
    strcpy(buffer, input);
}

void exploit() {
    char payload[80];
    memset(payload, 'A', sizeof(payload)-1);
    payload[sizeof(payload)-1] = '\0';

    void (*functionPointer)();
    functionPointer = (void (*)())payload;
    vulnerableFunction(payload);
    functionPointer();
}

int main() {
    char userData[128];
    printf("Enter your data: ");
    gets(userData);
    vulnerableFunction(userData);
    return 0;
}