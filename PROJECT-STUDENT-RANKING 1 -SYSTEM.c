#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_number;
    char name[50];
    int internal_marks[3];
    int cta;
    int cie;
} Student;

void calculateCIE(Student *student) {
    int temp;
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (student->internal_marks[i] < student->internal_marks[j]) {
                temp = student->internal_marks[i];
                student->internal_marks[i] = student->internal_marks[j];
                student->internal_marks[j] = temp;
            }
        }
    }
    student->cie = student->internal_marks[0] + student->internal_marks[1] + student->cta;
}

void rankStudents(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].cie < students[j].cie) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    Student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &students[i].roll_number);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Enter marks for 3 internal exams (out of 20): ");
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].internal_marks[j]);
        }
        printf("Enter teacher-allotted CTA (out of 10): ");
        scanf("%d", &students[i].cta);

        calculateCIE(&students[i]);
    }

    rankStudents(students, n);

    printf("\nRanked list of students based on CIE (highest to lowest):\n");
    printf("Rank\tRoll No\tName\t\tCIE Marks\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%-10s\t%d\n", i + 1, students[i].roll_number, students[i].name, students[i].cie);
    }

    return 0;
}
