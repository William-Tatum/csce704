#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

volatile sig_atomic_t flag = 0;
char *shared_state = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void signal_handler(int signal) {
    flag = 1;
}

void cleanup() {
    pthread_mutex_lock(&lock);
    if (shared_state != NULL) {
        free(shared_state);
        shared_state = NULL;
    }
    pthread_mutex_unlock(&lock);
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
            pthread_mutex_lock(&lock);
            if (shared_state != NULL) {
                free(shared_state);
                shared_state = NULL;
                printf("State was freed by signal\n");
            }
            pthread_mutex_unlock(&lock);
            break;
        }
        usleep(100000);
    }

    cleanup();
    pthread_mutex_destroy(&lock);

    return 0;
}