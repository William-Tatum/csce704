#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jumpBuffer;

void cleanup() {
    printf("Cleanup executed.\n");
    // Add necessary resource deallocation here
}

void process(int val) {
    if (val == 0) {
        longjmp(jumpBuffer, 1);
    }
    printf("Processing value: %d\n", val);
}

int main() {
    if (setjmp(jumpBuffer) != 0) {
        cleanup();
        return EXIT_FAILURE; // Indicate failure due to longjmp
    }

    for (int i = 5; i >= -1; i--) {
        process(i);
    }

    cleanup(); // Proper cleanup in normal execution path
    return EXIT_SUCCESS;
}