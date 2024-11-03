#include <stdio.h>
#include <math.h>

int main(void) {
    const int exercises = 50, exams = 100;
    int exer1, exer2, exer3, m_exam, f_exam;

    printf("Laboratory Exercise #1: "); scanf("%d", &exer1);
    printf("Laboratory Exercise #2: "); scanf("%d", &exer2);
    printf("Laboratory Exercise #3: "); scanf("%d", &exer3);
    printf("Midterm Exam: "); scanf("%d", &m_exam);
    printf("Final Exam: "); scanf("%d", &f_exam);

    printf("\nCourse:\t\tProgramming 1\n");
    printf("Exercises:\n");
    printf("\tLab Exercise 1:\t\t%d/%d\n", exer1, exercises);
    printf("\tLab Exercise 2:\t\t%d/%d\n", exer2, exercises);
    printf("\tLab Exercise 3:\t\t%d/%d\n", exer3, exercises);
    printf("Exams:\n");
    printf("\tMidterm Exam:\t\t%d/%d\n", m_exam, exams);
    printf("\tFinal Exam:\t\t%d/%d\n", f_exam, exams);

    float exerciseScore = ((exer1 + exer2 + exer3) / 150.0f) * 0.30f;
    float midtermScore = (m_exam / 100.0f) * 0.30f;
    float finalExamScore = (f_exam / 100.0f) * 0.40f;

    float studentRating = exerciseScore + midtermScore + finalExamScore;
    printf("\nFinal Grade:\t\t\t%.0f%%\n", studentRating*100.00f);
    return 0;
}