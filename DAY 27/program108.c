#include <stdio.h>
#include <string.h>

struct Subject {
    char name[30];
    int max_marks;
    int passing_marks;
    int obtained_marks;
};

struct Student {
    char name[50];
    char roll_no[15];
    char school_name[100];
    int total_subjects;
    struct Subject subjects[10];
    int total_obtained;
    int total_maximum;
    float percentage;
    char grade[3];
    char status[5];
};

void input_student_details(struct Student *s);
void calculate_results(struct Student *s);
void display_marksheet(const struct Student *s);

int main() {
    struct Student s;
    
    printf("=== MARKSHEET GENERATION SYSTEM ===\n\n");
    
    input_student_details(&s);
    calculate_results(&s);
    display_marksheet(&s);
    
    return 0;
}

void input_student_details(struct Student *s) {
    printf("Enter Student Full Name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = 0;

    printf("Enter Roll Number: ");
    fgets(s->roll_no, sizeof(s->roll_no), stdin);
    s->roll_no[strcspn(s->roll_no, "\n")] = 0;

    printf("Enter School/College Name: ");
    fgets(s->school_name, sizeof(s->school_name), stdin);
    s->school_name[strcspn(s->school_name, "\n")] = 0;

    printf("Enter Number of Subjects (Max 10): ");
    scanf("%d", &s->total_subjects);
    if (s->total_subjects > 10) s->total_subjects = 10;
    if (s->total_subjects < 1) s->total_subjects = 1;

    for (int i = 0; i < s->total_subjects; i++) {
        printf("\n--- Details for Subject %d ---\n", i + 1);
        printf("Enter Subject Name: ");
        scanf("%s", s->subjects[i].name);
        
        s->subjects[i].max_marks = 100;      
        s->subjects[i].passing_marks = 33;   
        
        do {
            printf("Enter Marks Obtained (0 to 100): ");
            scanf("%d", &s->subjects[i].obtained_marks);
            if (s->subjects[i].obtained_marks < 0 || s->subjects[i].obtained_marks > 100) {
                printf("Invalid marks! Please enter a value between 0 and 100.\n");
            }
        } while (s->subjects[i].obtained_marks < 0 || s->subjects[i].obtained_marks > 100);
    }
}

void calculate_results(struct Student *s) {
    s->total_obtained = 0;
    s->total_maximum = 0;
    int failed_any_subject = 0;

    for (int i = 0; i < s->total_subjects; i++) {
        s->total_obtained += s->subjects[i].obtained_marks;
        s->total_maximum += s->subjects[i].max_marks;
        
        if (s->subjects[i].obtained_marks < s->subjects[i].passing_marks) {
            failed_any_subject = 1;
        }
    }

    s->percentage = ((float)s->total_obtained / s->total_maximum) * 100;

    if (s->percentage >= 90) strcpy(s->grade, "A+");
    else if (s->percentage >= 80) strcpy(s->grade, "A");
    else if (s->percentage >= 70) strcpy(s->grade, "B");
    else if (s->percentage >= 60) strcpy(s->grade, "C");
    else if (s->percentage >= 50) strcpy(s->grade, "D");
    else if (s->percentage >= 33) strcpy(s->grade, "E");
    else strcpy(s->grade, "F");

    if (failed_any_subject || s->percentage < 33) {
        strcpy(s->status, "FAIL");
    } else {
        strcpy(s->status, "PASS");
    }
}

void display_marksheet(const struct Student *s) {
    printf("\n\n=================================================================\n");
    printf("                       PROGRESS REPORT CARD                      \n");
    printf("=================================================================\n");
    printf(" Institution : %-48s\n", s->school_name);
    printf(" Student Name: %-30s Roll No: %-10s\n", s->name, s->roll_no);
    printf("-----------------------------------------------------------------\n");
    printf(" %-20s | %-12s | %-12s | %-10s \n", "Subject Name", "Max Marks", "Pass Marks", "Obtained");
    printf("-----------------------------------------------------------------\n");
    
    for (int i = 0; i < s->total_subjects; i++) {
        printf(" %-20s | %-12d | %-12d | %-10d \n", 
               s->subjects[i].name, 
               s->subjects[i].max_marks, 
               s->subjects[i].passing_marks, 
               s->subjects[i].obtained_marks);
    }
    
    printf("-----------------------------------------------------------------\n");
    printf(" TOTAL MARKS: %d / %d                                     \n", s->total_obtained, s->total_maximum);
    printf(" PERCENTAGE : %.2f%%                                            \n", s->percentage);
    printf(" FINAL GRADE: %-5s                                              \n", s->grade);
    printf(" STATUS     : %-10s                                           \n", s->status);
    printf("=================================================================\n");
}
