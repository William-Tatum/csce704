#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>

volatile sig_atomic_t signal_received = 0;

void safe_signal_handler(int signum) {
    signal_received = signum;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = safe_signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    openlog("SignalHandler", LOG_PID | LOG_CONS, LOG_USER);

    while (1) {
        pause();
        if (signal_received) {
            syslog(LOG_NOTICE, "Signal received: %d", signal_received);
            signal_received = 0;
        }
    }

    closelog();
    return 0;
}