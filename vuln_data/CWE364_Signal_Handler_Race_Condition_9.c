#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t flag = 0;
char *shared_state = NULL;

void signal_handler(int signal) {
    flag = 1;
    if (shared_state != NULL) {
        // Risk of race condition if multiple signals arrive 
        // Here, free is a non-reentrant unsafe operation for a signal context
        free(shared_state); 
        shared_state = NULL; 
    }
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = signal_handler;
    sigaction(SIGUSR1, &sa, NULL);

    shared_state = malloc(128);
    strcpy(shared_state, "Initial state");

    while (1) {
        if (flag) {
            printf("State was freed by signal\n");
            break;
        }
        // Simulating work
        usleep(100000);
    }

    return 0;
}