#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>

volatile sig_atomic_t signal_received = 0;

void safe_signal_handler(int signal) {
    signal_received = signal;
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = safe_signal_handler;
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    openlog("SignalExample", LOG_PID|LOG_CONS, LOG_USER);

    while (1) {
        if (signal_received) {
            syslog(LOG_INFO, "Received Signal: %d", signal_received);
            signal_received = 0;
        }
        printf("Running...\n");
        sleep(1);
    }

    closelog();
    return 0;
}