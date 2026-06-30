#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
};

void addStudent(struct Student students[], int *count);
void displayStudents(const struct Student students[], int count);
void searchStudent(const struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Record system is full!\n");
        return;
    }

    struct Student newStudent;
    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);

    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == newStudent.rollNumber) {
            printf("Error: Student with Roll Number %d already exists.\n", newStudent.rollNumber);
            return;
        }
    }

    while (getchar() != '\n'); 

    printf("Enter Student Name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    students[*count] = newStudent;
    (*count)++;
    printf("Record added successfully!\n");
}

void displayStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

void searchStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchRoll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == searchRoll) {
            printf("\nRecord Found!\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("Marks:       %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", searchRoll);
}
