#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>

void unsafe_signal_handler(int signum) {
    syslog(LOG_INFO, "Signal received: %d", signum);
}

int main() {
    signal(SIGINT, unsafe_signal_handler);
    while (1) {
        sleep(1);
    }
    return 0;
}