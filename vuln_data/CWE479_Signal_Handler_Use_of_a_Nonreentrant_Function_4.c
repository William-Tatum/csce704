#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>

void handle_signal(int signal) {
    syslog(LOG_INFO, "Received signal %d", signal);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        pause();
    }

    return 0;
}