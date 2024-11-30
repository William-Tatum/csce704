#include <stdio.h>

void checkDay(int day) {
    if (day >= 1 && day <= 7) {
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
        }
    } else {
        printf("Invalid day\n");
    }
}

int main() {
    checkDay(3);
    checkDay(8);
    return 0;
}