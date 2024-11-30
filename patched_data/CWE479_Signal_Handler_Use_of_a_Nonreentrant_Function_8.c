#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("Signal received: %d\n", signal);
        exit(1);
    }
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    
    while (1) {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}