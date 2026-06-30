#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
    int is_issued;
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n*** MINI LIBRARY SYSTEM MENU ***");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nThank you for using the Library System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection! Choose a number between 1 and 6.\n");
        }
    }
    return 0;
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    struct Book new_book;
    
    printf("\nEnter Book ID (integer): ");
    scanf("%d", &new_book.id);
    while (getchar() != '\n');

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("Error: A book with ID %d already exists.\n", new_book.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; 

    printf("Enter Author Name: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;

    printf("Enter Book Price: ");
    scanf("%f", &new_book.price);
    
    new_book.is_issued = 0;

    library[book_count] = new_book;
    book_count++;

    printf("\nBook added successfully!\n");
}

void displayBooks() {
    if (book_count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-10s %-12s", "Book ID", "Title", "Author", "Price", "Status");
    printf("\n--------------------------------------------------------------------------------");
    for (int i = 0; i < book_count; i++) {
        printf("\n%-10d %-25s %-20s %-10.2f %-12s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].price, 
               (library[i].is_issued == 1) ? "Issued" : "Available");
    }
    printf("\n--------------------------------------------------------------------------------\n");
}

void searchBook() {
    if (book_count == 0) {
        printf("\nNo records to search.\n");
        return;
    }

    int search_id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            printf("\n--- Book Found ---");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nPrice: $%.2f", library[i].price);
            printf("\nStatus: %s\n", (library[i].is_issued == 1) ? "Issued" : "Available");
            return;
        }
    }
    printf("\nBook with ID %d not found.\n", search_id);
}

void issueBook() {
    if (book_count == 0) {
        printf("\nNo books available to issue.\n");
        return;
    }

    int issue_id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issue_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == issue_id) {
            if (library[i].is_issued == 1) {
                printf("\nThis book is already issued to someone else.\n");
                return;
            }
            library[i].is_issued = 1;
            printf("\nBook '%s' issued successfully!\n", library[i].title);
            return;
        }
    }
    printf("\nBook with ID %d does not exist.\n", issue_id);
}

void returnBook() {
    if (book_count == 0) {
        printf("\nNo books to process.\n");
        return;
    }

    int return_id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &return_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == return_id) {
            if (library[i].is_issued == 0) {
                printf("\nThis book was not issued. It is already in the library.\n");
                return;
            }
            library[i].is_issued = 0;
            printf("\nBook '%s' returned successfully!\n", library[i].title);
            return;
        }
    }
    printf("\nBook with ID %d does not belong to this library.\n", return_id);
}
