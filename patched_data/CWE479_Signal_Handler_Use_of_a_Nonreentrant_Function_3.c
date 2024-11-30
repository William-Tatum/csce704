#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void signal_handler(int signum) {
    printf("Received signal %d\n", signum);
    fflush(stdout);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();
    }
}