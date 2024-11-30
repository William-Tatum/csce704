#include <stdio.h>

void printDayOfWeek(int day) {
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day\n");
            break;
    }
}

int main() {
    int day;
    for (day = 1; day <= 7; ++day) {
        printDayOfWeek(day);
    }
    printDayOfWeek(0);
    printDayOfWeek(8);
    return 0;
}