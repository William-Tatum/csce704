#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>

void unsafe_signal_handler(int signum) {
    syslog(LOG_NOTICE, "Signal received: %d", signum); // Non-reentrant function
}

int main() {
    struct sigaction sa;
    sa.sa_handler = unsafe_signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    while (1) {
        pause();
    }

    return 0;
}