#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>

void signal_handler(int signum) {
    syslog(LOG_INFO, "Received signal %d", signum);
}

int main() {
    signal(SIGINT, signal_handler);
    openlog("CWE-479", LOG_PID|LOG_CONS, LOG_USER);
    while (1) {
        syslog(LOG_INFO, "Running program...");
        sleep(1);
    }
    closelog();
    return 0;
}