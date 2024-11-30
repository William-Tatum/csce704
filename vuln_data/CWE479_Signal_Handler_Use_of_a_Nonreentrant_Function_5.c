#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>

void signal_handler(int signum) {
    syslog(LOG_INFO, "Signal received: %d", signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);

    while (1) {
        pause();
    }
    return 0;
}