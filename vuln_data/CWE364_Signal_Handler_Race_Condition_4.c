#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t signal_received = 0;

void signal_handler(int signum) {
    signal_received = 1;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (signal_received) {
            printf("Signal received, handling...\n");
            signal_received = 0;
        }
        sleep(1);
    }

    return 0;
}