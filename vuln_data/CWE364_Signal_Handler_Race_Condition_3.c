#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0;
char *shared_ptr = NULL;

void handler(int signo) {
    if (shared_ptr) {
        free(shared_ptr);
    }
    flag = 1;
}

int main() {
    signal(SIGINT, handler);
    while (!flag) {
        shared_ptr = (char *)malloc(1024);
        if (!shared_ptr) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        printf("Memory allocated\n");
        sleep(1);
    }
    printf("Exiting safely\n");
    return 0;
}