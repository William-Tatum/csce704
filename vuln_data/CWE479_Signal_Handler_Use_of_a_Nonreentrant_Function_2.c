#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

void unsafe_signal_handler(int signo) {
    syslog(LOG_INFO, "Received signal %d", signo);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = unsafe_signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    while (1) {
        pause();
    }

    return 0;
}