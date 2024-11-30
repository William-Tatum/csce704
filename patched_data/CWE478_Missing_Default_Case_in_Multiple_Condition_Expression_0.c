#include <stdio.h>

void evaluateGrade(char grade) {
    switch (grade) {
        case 'A':
            printf("Excellent\n");
            break;
        case 'B':
            printf("Good\n");
            break;
        case 'C':
            printf("Average\n");
            break;
        case 'D':
            printf("Below Average\n");
            break;
        case 'F':
            printf("Fail\n");
            break;
        default:
            printf("Invalid grade\n");
            break;
    }
}

int main() {
    char grade;
    printf("Enter a grade (A, B, C, D, F): ");
    if (scanf(" %c", &grade) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    evaluateGrade(grade);
    return 0;
}