#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0;

void handle_signal(int signal) {
    flag = 1;
}

void process_critical_section() {
    if (flag) {
        printf("Signal handled!\n");
        flag = 0;
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        process_critical_section();
        sleep(1);
    }

    return 0;
}