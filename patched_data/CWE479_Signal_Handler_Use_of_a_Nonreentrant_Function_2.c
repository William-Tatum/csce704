#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

volatile sig_atomic_t sig_received = 0;

void safe_signal_handler(int signo) {
    sig_received = signo;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = safe_signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    openlog("signal_handler", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

    while (1) {
        pause();
        if (sig_received) {
            syslog(LOG_INFO, "Received signal %d", sig_received);
            sig_received = 0;
        }
    }

    closelog();
    return 0;
}