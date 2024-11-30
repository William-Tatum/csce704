#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t fatal_error_in_progress = 0;

void signal_handler(int signal) {
    if (fatal_error_in_progress)
        raise(signal);
    fatal_error_in_progress = 1;

    write(STDERR_FILENO, "Signal received\n", 16);
    
    fatal_error_in_progress = 0;
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    while (1) {
        sleep(1);
    }

    return EXIT_SUCCESS;
}