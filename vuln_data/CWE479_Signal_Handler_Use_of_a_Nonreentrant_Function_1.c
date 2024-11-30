#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>

void unsafe_signal_handler(int signal) {
    syslog(LOG_INFO, "Received Signal: %d", signal);
}

int main() {
    signal(SIGINT, unsafe_signal_handler);
    while (1) {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}