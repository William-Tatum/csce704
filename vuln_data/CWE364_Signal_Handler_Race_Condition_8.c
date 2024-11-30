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
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        if (flag) {
            printf("Signal received\n");
            flag = 0;
        }
        sleep(1);
    }

    return 0;
}