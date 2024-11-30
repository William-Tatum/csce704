#include <stdio.h>
#include <string.h>

void untrusted_function(char *mutable_data) {
    strcpy(mutable_data, "Hacked data!");
}

int main() {
    char sensitive_data[50] = "Sensitive Data";

    char clone_data[50];
    strcpy(clone_data, sensitive_data);

    untrusted_function(clone_data);

    printf("Original Data: %s\n", sensitive_data);
    printf("Clone Data: %s\n", clone_data);

    return 0;
}