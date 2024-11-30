#include <stdio.h>

void evaluate_grade(char grade) {
    switch (grade) {
        case 'A':
            printf("Excellent!\n");
            break;
        case 'B':
            printf("Well done!\n");
            break;
        case 'C':
            printf("Good\n");
            break;
        case 'D':
            printf("Needs improvement.\n");
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
    printf("Enter grade (A, B, C, D, F): ");
    if (scanf(" %c", &grade) != 1 || !(grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'F')) {
        printf("Invalid input\n");
        return 1;
    }
    evaluate_grade(grade);
    return 0;
}