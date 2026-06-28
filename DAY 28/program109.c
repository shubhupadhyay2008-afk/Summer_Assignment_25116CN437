#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "library_data.dat"

typedef struct {
    int id;
    char title[50];
    char author[50];
    int is_issued;
} Book;

void add_book();
void display_books();
void search_book();
void issue_book();
void return_book();
void clear_input_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== LIBRARY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: search_book(); break;
            case 4: issue_book(); break;
            case 5: return_book(); break;
            case 6: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void add_book() {
    FILE *file = fopen(DATA_FILE, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Book my_book;
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &my_book.id);
    clear_input_buffer();

    printf("Enter Book Title: ");
    fgets(my_book.title, sizeof(my_book.title), stdin);
    my_book.title[strcspn(my_book.title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(my_book.author, sizeof(my_book.author), stdin);
    my_book.author[strcspn(my_book.author, "\n")] = '\0';

    my_book.is_issued = 0;

    fwrite(&my_book, sizeof(Book), 1, file);
    fclose(file);

    printf("Book added successfully!\n");
}

void display_books() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file == NULL) {
        printf("\nNo library data found. Please add a book first.\n");
        return;
    }

    Book my_book;
    printf("\n%-10s %-30s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("----------------------------------------------------------------------------\n");

    while (fread(&my_book, sizeof(Book), 1, file) == 1) {
        printf("%-10d %-30s %-25s %-15s\n", 
               my_book.id, 
               my_book.title, 
               my_book.author, 
               my_book.is_issued ? "Issued" : "Available");
    }
    fclose(file);
}

void search_book() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file == NULL) {
        printf("\nNo library data found.\n");
        return;
    }

    int search_id, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &search_id);

    Book my_book;
    while (fread(&my_book, sizeof(Book), 1, file) == 1) {
        if (my_book.id == search_id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                   my_book.id, my_book.title, my_book.author, 
                   my_book.is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Book with ID %d not found.\n", search_id);
    }
}

void issue_book() {
    FILE *file = fopen(DATA_FILE, "rb+");
    if (file == NULL) {
        printf("\nNo library data found.\n");
        return;
    }

    int target_id, found = 0;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &target_id);

    Book my_book;
    while (fread(&my_book, sizeof(Book), 1, file) == 1) {
        if (my_book.id == target_id) {
            found = 1;
            if (my_book.is_issued == 1) {
                printf("This book is already issued to someone else.\n");
            } else {
                my_book.is_issued = 1;
                fseek(file, -sizeof(Book), SEEK_CUR);
                fwrite(&my_book, sizeof(Book), 1, file);
                printf("Book successfully issued!\n");
            }
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Book ID %d not found.\n", target_id);
    }
}

void return_book() {
    FILE *file = fopen(DATA_FILE, "rb+");
    if (file == NULL) {
        printf("\nNo library data found.\n");
        return;
    }

    int target_id, found = 0;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &target_id);

    Book my_book;
    while (fread(&my_book, sizeof(Book), 1, file) == 1) {
        if (my_book.id == target_id) {
            found = 1;
            if (my_book.is_issued == 0) {
                printf("This book was not issued. It is already in the library.\n");
            } else {
                my_book.is_issued = 0;
                fseek(file, -sizeof(Book), SEEK_CUR);
                fwrite(&my_book, sizeof(Book), 1, file);
                printf("Book successfully returned to the library!\n");
            }
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Book ID %d not found.\n", target_id);
    }
}
