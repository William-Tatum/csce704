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
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        if (flag) {
            if (write(STDOUT_FILENO, "Signal caught\n", 14) == -1) {
                perror("write");
                return 1;
            }
            flag = 0;
        }
        sleep(1);
    }
    return 0;
}