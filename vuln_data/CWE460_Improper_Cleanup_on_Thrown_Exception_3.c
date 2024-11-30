#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jumpBuffer;

void cleanup() {
    // Improper cleanup function
    printf("Improper cleanup executed.\n");
}

void process(int val) {
    if (val == 0) {
        longjmp(jumpBuffer, 1);
    }
    printf("Processing value: %d\n", val);
}

int main() {
    int returnValue = setjmp(jumpBuffer);
    if (returnValue != 0) {
        cleanup();
    } else {
        for (int i = 5; i >= -1; i--) {
            process(i);
        }
    }
    return 0;
}