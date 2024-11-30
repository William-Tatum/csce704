#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t got_signal = 0;

void signal_handler(int signum) {
    got_signal = 1;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();
        if (got_signal) {
            printf("Signal received and processed.\n");
            got_signal = 0;
        }
    }

    return 0;
}