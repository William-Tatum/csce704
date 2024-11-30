#include <stdio.h>
#include <string.h>

void untrusted_function(const char *immutable_data) {
    // Function does not modify data
}

int main() {
    const char *sensitive_data = "Sensitive Data";

    char clone_data[50];
    strncpy(clone_data, sensitive_data, sizeof(clone_data) - 1);
    clone_data[sizeof(clone_data) - 1] = '\0';

    untrusted_function(clone_data);

    printf("Original Data: %s\n", sensitive_data);
    printf("Clone Data: %s\n", clone_data);

    return 0;
}