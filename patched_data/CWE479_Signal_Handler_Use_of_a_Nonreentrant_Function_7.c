#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

volatile sig_atomic_t flag = 0;

void safeSignalHandler(int signum) {
    flag = signum;
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = safeSignalHandler;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
    }

    openlog("my_program", LOG_PID | LOG_CONS, LOG_USER);
    
    while (1) {
        if (flag) {
            syslog(LOG_INFO, "Signal %d received", flag);
            printf("Caught signal %d\n", flag);
            flag = 0;
        }
        pause();
    }

    closelog();
    return 0;
}