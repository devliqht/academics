#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fName[20];
    char lName[20];
    char MI;
} name;

typedef struct {
    name empName;
    int idNum;
    int grossSalary;
    int rate;
    int hrsWorked;
    float takeHomeSalary;
} employeeInfo;

typedef struct {
    employeeInfo* employees;
    int count;
} employeeRecord;

typedef struct {
    employeeRecord employeeList;
    employeeRecord bracket1, bracket2, bracket3;
} companyRecord;

name addName(char fName[], char lName[], char MI);
employeeInfo newEmployee(int idNum, int rate, int hrsWorked, name employeeName);
employeeRecord populate(int count);
void taxBracketSeparation(companyRecord* companyList);

int main(void) {
    int employeesCount;
    printf("Input how many employees: ");
    scanf("%d", &employeesCount);
    employeeRecord record = populate(employeesCount);
    companyRecord companyRecord;
    if (record.employees == NULL) {
        printf("Dynamic Memory Allocation Failed.");
        return 1;
    }

    for (int i = 0; i < employeesCount; i++) {
        int idNum, rate, hrsWorked;
        char fName[20], lName[20], MI;
        printf("\n===EMPLOYEE %d===\n", i+1);
        printf("Enter ID Number: ");
        scanf("%d", &idNum);
        printf("Enter First Name: ");
        scanf(" %[^\n]s", fName);
        printf("Enter Last Name: ");
        scanf(" %[^\n]s", lName);
        printf("Enter Middle Initial: ");
        scanf(" %c", &MI);
        printf("Enter Hourly Rate: ");
        scanf("%d", &rate);
        printf("Enter Hours Worked: ");
        scanf("%d", &hrsWorked);
        record.employees[i] = newEmployee(idNum, rate, hrsWorked, addName(fName, lName, MI));
    }

    companyRecord.employeeList = record;
    taxBracketSeparation(&companyRecord);
    printf("\n===BRACKET 1===\n");
    for (int i = 0; i < companyRecord.bracket1.count; i++) {
        printf("%d - %s, %s %c --- Php %.2f\n", companyRecord.bracket1.employees[i].idNum, companyRecord.bracket1.employees[i].empName.lName, companyRecord.bracket1.employees[i].empName.fName, companyRecord.bracket1.employees[i].empName.MI, companyRecord.bracket1.employees[i].takeHomeSalary);
    }

    printf("\n===BRACKET 2===\n");
    for (int i = 0; i < companyRecord.bracket2.count; i++) {
        printf("%d - %s, %s %c --- Php %.2f\n", companyRecord.bracket2.employees[i].idNum, companyRecord.bracket2.employees[i].empName.lName, companyRecord.bracket2.employees[i].empName.fName, companyRecord.bracket2.employees[i].empName.MI, companyRecord.bracket2.employees[i].takeHomeSalary);
    }

    printf("\n===BRACKET 3===\n");
    for (int i = 0; i < companyRecord.bracket3.count; i++) {
        printf("%d - %s, %s %c --- Php %.2f\n", companyRecord.bracket3.employees[i].idNum, companyRecord.bracket3.employees[i].empName.lName, companyRecord.bracket3.employees[i].empName.fName, companyRecord.bracket3.employees[i].empName.MI, companyRecord.bracket3.employees[i].takeHomeSalary);
    }

    free(record.employees);
    free(companyRecord.bracket1.employees);
    free(companyRecord.bracket2.employees);
    free(companyRecord.bracket3.employees);
    free(companyRecord.employeeList.employees);

    return 0;
}

name addName(char fName[], char lName[], char MI) {
    name temp;
    strcpy(temp.fName, fName);
    strcpy(temp.lName, lName);
    temp.MI = MI;

    return temp;
}

employeeInfo newEmployee(int idNum, int rate, int hrsWorked, name employeeName) {
    employeeInfo tempEmp;
    tempEmp.idNum = idNum;
    tempEmp.rate = rate;
    tempEmp.hrsWorked = hrsWorked;
    tempEmp.empName = employeeName;
    tempEmp.grossSalary = tempEmp.rate * tempEmp.hrsWorked;

    return tempEmp;
}

employeeRecord populate(int count) {
    employeeRecord temp;
    temp.employees = (employeeInfo*)malloc(count * sizeof(employeeInfo));
    temp.count = count;

    return temp;
}

void taxBracketSeparation(companyRecord* companyList) {
    companyList->bracket1.count = 0;
    companyList->bracket2.count = 0;
    companyList->bracket3.count = 0;

    for (int i = 0; i < companyList->employeeList.count; i++) {
        float empGrossSalary = companyList->employeeList.employees[i].grossSalary;
        if (empGrossSalary < 15000) {
            companyList->employeeList.employees[i].takeHomeSalary = empGrossSalary * 0.90f;
            companyList->bracket1.count++;
        } else if (empGrossSalary >= 15000 &&  empGrossSalary < 26000) {
            companyList->employeeList.employees[i].takeHomeSalary = empGrossSalary * 0.85f;
            companyList->bracket2.count++;
        } else if (empGrossSalary >= 26000) {
            companyList->employeeList.employees[i].takeHomeSalary = empGrossSalary * 0.80f;
            companyList->bracket3.count++;
        }
    }

    companyList->bracket1 = populate(companyList->bracket1.count);
    companyList->bracket2 = populate(companyList->bracket2.count);
    companyList->bracket3 = populate(companyList->bracket3.count);

    int bracket1idx = 0, bracket2idx = 0, bracket3idx = 0;

    for (int i = 0; i < companyList->employeeList.count; i++) {
        float empGrossSalary = companyList->employeeList.employees[i].grossSalary;
        if (empGrossSalary < 15000) {
            companyList->bracket1.employees[bracket1idx++] = companyList->employeeList.employees[i];
        } else if (empGrossSalary >= 15000 &&  empGrossSalary < 26000) {
            companyList->bracket2.employees[bracket2idx++] = companyList->employeeList.employees[i];
        } else if (empGrossSalary >= 26000) {
            companyList->bracket3.employees[bracket3idx++] = companyList->employeeList.employees[i];
        }
    }
}