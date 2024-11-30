#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0;

void handler(int signum) {
    flag = 1;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (flag) {
            if (printf("Signal received\n") < 0) {
                perror("printf");
                exit(EXIT_FAILURE);
            }
            flag = 0;
        }
        sleep(1);
    }

    return 0;
}