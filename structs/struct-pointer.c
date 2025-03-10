#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char employeeName[50];
    int employeeID;
    double salary;
} Employee;

void updateSalary(Employee *employeePtr, double newSalary);
void printEmployee(const Employee *employeePtr);

int main(void) {
    Employee employees[3] = {
        {"John Doe", 301, 50000.00},
        {"Jane Smith", 302, 60000.50},
        {"David Lee", 303, 75000.75}
    };
    
    printf("Original Employee Information:\n");
    for (int i = 0; i < 3; i++) {
        printEmployee(employees+i);
    }
    
    updateSalary(employees+1, 65000.00);
    printf("Updated Employee Information:\n");
    for (int i = 0; i < 3; i++) {
        printEmployee(employees+i);
    }
    
    Employee* newEmployee = (Employee*)malloc(1 * sizeof(Employee));
    if (newEmployee == NULL) {
        printf("Dynamic Allocation Failed.\n");
        return 1;
    }
    
    strcpy(newEmployee->employeeName, "Emily White");
    newEmployee->employeeID = 304;
    newEmployee->salary = 80000.00;
    
    printf("Dynamically allocated Employee Information:\n");
    printEmployee(newEmployee);
    
    free(newEmployee);
    return 0;
    
}

void updateSalary(Employee *employeePtr, double newSalary) {
    employeePtr->salary = newSalary;
}

void printEmployee(const Employee *employeePtr){
    printf("Employee ID: %d\n", employeePtr->employeeID);
    printf("Employee Name: %s\n", employeePtr->employeeName);
    printf("Salary: %0.2lf\n", employeePtr->salary);
    putchar('\n');
}