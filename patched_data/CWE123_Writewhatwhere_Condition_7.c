#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[50];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
}

void secure_function() {
    char safe_message[] = "Secure code execution!";
    printf("%s\n", safe_message);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    void (*func_ptr)() = secure_function;
    vulnerable_function(argv[1]);
    func_ptr();
    return 0;
}