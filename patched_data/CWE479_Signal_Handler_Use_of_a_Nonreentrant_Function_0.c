#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

void signal_handler(int signum) {
    syslog(LOG_INFO, "Received signal %d", signum);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = signal_handler;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        fprintf(stderr, "Failed to set signal handler: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    openlog("CWE-479", LOG_PID|LOG_CONS, LOG_USER);

    while (1) {
        syslog(LOG_INFO, "Running program...");
        sleep(1);
    }

    closelog();
    return 0;
}