#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void platform_sleep(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

int main() {
    int delay = 1000;
    printf("Starting delay...\n");
    platform_sleep(delay);
    printf("Delay completed.\n");
    return 0;
}