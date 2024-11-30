#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int signal) {
    printf("Signal received: %d\n", signal);
    exit(1);
}

int main() {
    signal(SIGINT, handle_signal);
    while (1) {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}