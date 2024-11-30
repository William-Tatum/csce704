#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t counter = 0;

void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        counter++;
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Counter: %d\n", counter);
        sleep(1);
    }

    return 0;
}