#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0;
volatile sig_atomic_t cleanup_needed = 0;
char *shared_ptr = NULL;

void handler(int signo) {
    flag = 1;
}

void cleanup() {
    if (cleanup_needed && shared_ptr) {
        free(shared_ptr);
        shared_ptr = NULL;
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    while (!flag) {
        shared_ptr = (char *)malloc(1024);
        if (!shared_ptr) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        cleanup_needed = 1;
        printf("Memory allocated\n");
        sleep(1);
        cleanup();
    }

    cleanup();
    printf("Exiting safely\n");
    return 0;
}