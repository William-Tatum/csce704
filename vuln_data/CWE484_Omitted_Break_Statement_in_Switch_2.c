#include <stdio.h>

void checkGrade(char grade) {
    switch (grade) {
        case 'A':
            printf("Excellent\n");
        case 'B':
            printf("Good\n");
        case 'C':
            printf("Average\n");
        case 'D':
            printf("Below Average\n");
        case 'F':
            printf("Fail\n");
        default:
            printf("Invalid grade\n");
    }
}

int main() {
    char grade = 'B';
    checkGrade(grade);
    return 0;
}