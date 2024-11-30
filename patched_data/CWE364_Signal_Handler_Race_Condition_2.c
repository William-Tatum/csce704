#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t fatal_error_in_progress = 0;

void signal_handler(int signal) {
    if (fatal_error_in_progress)
        raise(signal);
    fatal_error_in_progress = 1;

    const char *msg = "Signal received\n";
    write(STDERR_FILENO, msg, strlen(msg));

    _Exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction for SIGINT failed");
        exit(EXIT_FAILURE);
    }
    
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("sigaction for SIGTERM failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();
    }

    return EXIT_SUCCESS;
}