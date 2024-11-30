#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0;

void signal_handler(int signo) {
    flag = 1;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        if (flag) {
            printf("Signal caught\n");
            flag = 0;
        }
        sleep(1);
    }
    return 0;
}