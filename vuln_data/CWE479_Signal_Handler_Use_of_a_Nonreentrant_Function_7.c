#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void unsafeSignalHandler(int signum) {
    printf("Caught signal %d\n", signum);
    syslog(LOG_INFO, "Signal %d received", signum);
}

int main() {
    if (signal(SIGINT, unsafeSignalHandler) == SIG_ERR) {
        printf("Error setting up signal handler\n");
        exit(1);
    }
    while (1) {
        pause();
    }
    return 0;
}