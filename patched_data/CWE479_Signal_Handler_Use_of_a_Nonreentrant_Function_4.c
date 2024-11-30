#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>
#include <errno.h>
#include <stdlib.h>

void handle_signal(int signal) {
    syslog(LOG_INFO, "Received signal %d", signal);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = SA_RESTART;
    if (sigemptyset(&sa.sa_mask) == -1) {
        perror("Failed to initialize signal set");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Failed to set signal handler");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();
    }

    return 0;
}