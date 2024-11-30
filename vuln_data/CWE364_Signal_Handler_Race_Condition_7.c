#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t graceful_exit = 0;

void handle_signal(int signal) {
    graceful_exit = 1;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (!graceful_exit) {
        printf("Running...\n");
        sleep(1);
    }

    printf("Gracefully shutting down...\n");
    return 0;
}