#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void platform_sleep(int milliseconds) {
    if (milliseconds < 0) {
        fprintf(stderr, "Invalid delay time\n");
        exit(EXIT_FAILURE);
    }
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep((useconds_t) milliseconds * 1000);
#endif
}

int main() {
    int delay = 1000;
    printf("Starting delay...\n");
    platform_sleep(delay);
    printf("Delay completed.\n");
    return 0;
}