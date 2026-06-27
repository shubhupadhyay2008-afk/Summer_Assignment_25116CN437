#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[30];
    float basic_salary;
    float da;          
    float hra;         
    float pf;          
    float gross_salary;
    float net_salary;
};

struct Employee emp_list[MAX_EMPLOYEES];
int employee_count = 0;
void addEmployee();
void displayAllEmployees();
void searchEmployee();
void calculateSalary(struct Employee *emp);

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Salary Records");
        printf("\n3. Search Employee Salary Slip");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

void calculateSalary(struct Employee *emp) {
    emp->da = emp->basic_salary * 0.20;  
    emp->hra = emp->basic_salary * 0.15; 
    emp->pf = emp->basic_salary * 0.12;
    emp->gross_salary = emp->basic_salary + emp->da + emp->hra;
    emp->net_salary = emp->gross_salary - emp->pf;
}

void addEmployee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("\nSystem database is full! Cannot add more records.\n");
        return;
    }

    struct Employee new_emp;

    printf("\nEnter Employee ID (Integer): ");
    scanf("%d", &new_emp.id);
    getchar(); 

    printf("Enter Employee Name: ");
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = '\0';

    printf("Enter Designation: ");
    fgets(new_emp.designation, sizeof(new_emp.designation), stdin);
    new_emp.designation[strcspn(new_emp.designation, "\n")] = '\0';

    printf("Enter Basic Monthly Salary: ");
    scanf("%f", &new_emp.basic_salary);

    calculateSalary(&new_emp);
    emp_list[employee_count] = new_emp;
    employee_count++;

    printf("\nEmployee record added successfully!\n");
}

void displayAllEmployees() {
    if (employee_count == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }

    printf("\n====================================================================================================\n");
    printf("%-5s %-20s %-15s %-12s %-10s %-10s %-10s %-12s\n", 
           "ID", "Name", "Designation", "Basic Sal.", "DA", "HRA", "PF", "Net Salary");
    printf("====================================================================================================\n");

    for (int i = 0; i < employee_count; i++) {
        printf("%-5d %-20s %-15s %-12.2f %-10.2f %-10.2f %-10.2f %-12.2f\n",
               emp_list[i].id, 
               emp_list[i].name, 
               emp_list[i].designation, 
               emp_list[i].basic_salary, 
               emp_list[i].da, 
               emp_list[i].hra, 
               emp_list[i].pf, 
               emp_list[i].net_salary);
    }
    printf("====================================================================================================\n");
}
void searchEmployee() {
    if (employee_count == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }

    int search_id;
    int found = 0;

    printf("\nEnter Employee ID to generate salary slip: ");
    scanf("%d", &search_id);

    for (int i = 0; i < employee_count; i++) {
        if (emp_list[i].id == search_id) {
            found = 1;
            printf("\n=================================");
            printf("\n        EARNINGS STATEMENT       ");
            printf("\n=================================");
            printf("\nEmployee ID  : %d", emp_list[i].id);
            printf("\nName         : %s", emp_list[i].name);
            printf("\nDesignation  : %s", emp_list[i].designation);
            printf("\n---------------------------------");
            printf("\nBasic Salary : $%.2f", emp_list[i].basic_salary);
            printf("\nDA (20%%)     : $%.2f", emp_list[i].da);
            printf("\nHRA (15%%)    : $%.2f", emp_list[i].hra);
            printf("\nGross Salary : $%.2f", emp_list[i].gross_salary);
            printf("\n---------------------------------");
            printf("\nPF Ded. (12%%): $%.2f", emp_list[i].pf);
            printf("\n=================================");
            printf("\nNET PAYCHECK : $%.2f", emp_list[i].net_salary);
            printf("\n=================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }
}
