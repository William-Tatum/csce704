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
            break; // Fix: Added missing break
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
    char grade = 'C';
    evaluate_grade(grade);
    return 0;
}