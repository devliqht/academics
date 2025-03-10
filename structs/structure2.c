#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char courseName[50];
    float creditHours;
    float courseGrade;
} AcademicRecords;

typedef struct {
    char studentName[100];
    int studentID;
    int studentAge;
    int gradeLevel;
    float GPA;
    AcademicRecords studentRecords[2];
} Student;

Student registerStudent();
float calculateGPA(Student stud);
void listStudentsByGrade(Student students[], int count, int filter);

int main(void) {
    int choice, idx = 0, filter;
    Student students[10];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Register a new student\n2. Update student details\n3. List students by grade level\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                students[idx++] = registerStudent();
                break;
            case 2:
                printf("WIP\n");
                break;
            case 3: 
                printf("Enter grade level to filter: ");
                scanf("%d", &filter);
                listStudentsByGrade(students, idx, filter);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
        }
    }
}

Student registerStudent() {
    Student temp;
    int coursesAmt;
    
    printf("\nEnter student details:\n");
    printf("Name: "); 
    scanf(" %[^\n]s", temp.studentName);
    
    printf("Student ID: ");
    scanf("%d", &temp.studentID);
    
    printf("Age: ");
    scanf("%d", &temp.studentAge);
    
    printf("Grade Level: ");
    scanf("%d", &temp.gradeLevel);
    
    printf("Enter number of courses (max 2): ");
    scanf("%d", &coursesAmt);
    
    if (coursesAmt < 2 && coursesAmt != 0) {
        printf("Course 1 Name: ");
        scanf(" %[^\n]s", temp.studentRecords[0].courseName);
        printf("Credit Hours: ");
        scanf("%f", &temp.studentRecords[0].creditHours);
        
        printf("Grade (0.0 - 4.0 scale): ");
        scanf("%f", &temp.studentRecords[0].courseGrade);
        
        temp.studentRecords[1].creditHours = 896;
        temp.studentRecords[1].courseGrade = 0.0;

        temp.GPA = calculateGPA(temp);
    } else if (coursesAmt == 2) {
        for (int i = 0; i < 2; i++) {
              printf("Course %d Name: ", i+1);
            scanf(" %[^\n]s", temp.studentRecords[i].courseName);
            printf("Credit Hours: ");
            scanf("%f", &temp.studentRecords[i].creditHours);
        
            printf("Grade (0.0 - 4.0 scale): ");
            scanf("%f", &temp.studentRecords[i].courseGrade);
        }
        temp.GPA = calculateGPA(temp);
    }
    printf("Updated GPA: %.2f\n", temp.GPA);
    printf("Student registered successfully!\n");
    
    return temp;
}

float calculateGPA(Student stud) {
    float gpa = 0.0f;
    for (int i = 0; i < 2; i++) {
        gpa += (stud.studentRecords[i].courseGrade * stud.studentRecords[i].creditHours);
    }
    return gpa /= (stud.studentRecords[0].creditHours + stud.studentRecords[1].creditHours);
}

void listStudentsByGrade(Student students[], int count, int filter) {
    printf("\nStudents in Grade %d: \n", filter);
    for (int i = 0; i < count; i++) {
        if (students[i].gradeLevel == filter) {
            printf("\nStudent Name: %s\n", students[i].studentName);
            printf("Student ID: %d\n", students[i].studentID);
            printf("Age: %d\n", students[i].studentAge);
            printf("Grade Level: %d\n", students[i].gradeLevel);
            printf("GPA: %.2f\n", students[i].GPA);
            printf("Courses:\n");
            for (int j = 0; j < 2; j++) {
                printf("  - %s (%.0f Credit Hours) | Grade: %.2f\n", students[i].studentRecords[j].courseName, students[i].studentRecords[j].creditHours, students[i].studentRecords[j].courseGrade);
            }
        }
    }
}