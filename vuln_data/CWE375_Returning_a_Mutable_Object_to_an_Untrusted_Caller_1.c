#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Employee;

Employee* get_employee_duplicate(Employee *original) {
    if (original == NULL) return NULL;
    Employee *duplicate = malloc(sizeof(Employee));
    if (duplicate == NULL) return NULL;
    duplicate->id = original->id;
    strncpy(duplicate->name, original->name, sizeof(duplicate->name) - 1);
    duplicate->name[sizeof(duplicate->name) - 1] = '\0';
    return duplicate;
}

void free_employee(Employee *emp) {
    if (emp != NULL) {
        free(emp);
    }
}

int main() {
    Employee emp = {123, "John Doe"};
    Employee *emp_dup = get_employee_duplicate(&emp);
    if (emp_dup != NULL) {
        printf("ID: %d, Name: %s\n", emp_dup->id, emp_dup->name);
        free_employee(emp_dup);
    }
    return 0;
}