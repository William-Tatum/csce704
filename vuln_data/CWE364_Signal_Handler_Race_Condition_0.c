#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t got_signal = 0;

void signal_handler(int signum) {
    got_signal = 1;
}

int main() {
    signal(SIGINT, signal_handler);

    while (1) {
        if (got_signal) {
            printf("Signal received and processed.\n");
            got_signal = 0;
        }
    }

    return 0;
}