#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char dept[50];
    float salary;
};

void addEmployee();
void viewEmployees();
void searchEmployee();

const char *FILENAME = "employees.dat";

int main() {
    int choice;
    while (1) {
        printf("\n=== Employee Management System ===");
        printf("\n1. Add New Employee");
        printf("\n2. View All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addEmployee() {
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);
    printf("Enter Department: ");
    scanf(" %[^\n]s", emp.dept);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, file);
    fclose(file);
    printf("Employee added successfully!\n");
}

void viewEmployees() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("\nNo records found or file does not exist!\n");
        return;
    }

    struct Employee emp;
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("-----------------------------------------------------------------\n");
    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("%-10d %-20s %-20s $%.2f\n", emp.id, emp.name, emp.dept, emp.salary);
    }
    fclose(file);
}

void searchEmployee() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("\nNo records found or file does not exist!\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    struct Employee emp;
    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        if (emp.id == searchId) {
            printf("\nEmployee Found!\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: $%.2f\n", emp.id, emp.name, emp.dept, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
    fclose(file);
}
