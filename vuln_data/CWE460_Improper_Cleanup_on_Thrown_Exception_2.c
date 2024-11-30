#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void cleanup() {
    printf("Cleaning up resources...\n");
}

void do_risky_thing() {
    if (rand() % 2 == 0) {
        printf("An error occurred!\n");
        longjmp(env, 1);
    }
    printf("Risky operation successful.\n");
}

int main() {
    if (setjmp(env) != 0) {
        cleanup();
        return 1;
    }
    printf("Starting risky operation...\n");
    do_risky_thing();
    printf("Risky operation completed successfully.\n");
    cleanup();
    return 0;
}