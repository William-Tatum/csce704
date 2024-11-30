#include <stdio.h>

void checkTemperature(int temperature) {
    switch (temperature) {
        case 0:
            printf("Freezing point!\n");
        case 100:
            printf("Boiling point!\n");
            break;
        default:
            printf("Normal temperature\n");
            break;
    }
}

int main() {
    checkTemperature(0);
    checkTemperature(50);
    checkTemperature(100);
    return 0;
}