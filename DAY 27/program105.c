#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNumber;
    char name[50];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudentRecord();
void displayAllRecords();
void searchStudentRecord();
void updateStudentRecord();
void deleteStudentRecord();

int main() {
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n   STUDENT RECORD MANAGEMENT SYSTEM");
        printf("\n====================================");
        printf("\n1. Add Student Record");
        printf("\n2. Display All Student Records");
        printf("\n3. Search Student Record");
        printf("\n4. Update Student Record");
        printf("\n5. Delete Student Record");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                searchStudentRecord();
                break;
            case 4:
                updateStudentRecord();
                break;
            case 5:
                deleteStudentRecord();
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}

void addStudentRecord() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nError: Database is full! Cannot add more records.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nError: Student with Roll Number %d already exists!\n", roll);
            return;
        }
    }

    students[studentCount].rollNumber = roll;
    printf("Enter Name: ");
    getchar();
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter GPA: ");
    scanf("%f", &students[studentCount].gpa);

    studentCount++;
    printf("\nRecord added successfully!\n");
}

void displayAllRecords() {
    if (studentCount == 0) {
        printf("\nNo student records found to display.\n");
        return;
    }

    printf("\n------------------------------------------------");
    printf("\n%-12s %-25s %-5s", "Roll Number", "Name", "GPA");
    printf("\n------------------------------------------------");
    for (int i = 0; i < studentCount; i++) {
        printf("\n%-12d %-25s %-5.2f", students[i].rollNumber, students[i].name, students[i].gpa);
    }
    printf("\n------------------------------------------------\n");
}

void searchStudentRecord() {
    if (studentCount == 0) {
        printf("\nNo student records found to search.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nRecord Found!");
            printf("\nRoll Number: %d", students[i].rollNumber);
            printf("\nName:        %s", students[i].name);
            printf("\nGPA:         %.2f\n", students[i].gpa);
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", roll);
}

void updateStudentRecord() {
    if (studentCount == 0) {
        printf("\nNo student records found to update.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nCurrent Details -> Name: %s, GPA: %.2f", students[i].name, students[i].gpa);
            
            printf("\nEnter New Name: ");
            getchar();
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter New GPA: ");
            scanf("%f", &students[i].gpa);

            printf("\nRecord updated successfully!\n");
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", roll);
}

void deleteStudentRecord() {
    if (studentCount == 0) {
        printf("\nNo student records found to delete.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", roll);
}
