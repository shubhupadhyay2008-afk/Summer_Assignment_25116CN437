#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define STR_LEN 50

int bookIDs[MAX_BOOKS];
char bookTitles[MAX_BOOKS][STR_LEN];
char bookAuthors[MAX_BOOKS][STR_LEN];
int bookCount = 0;

void displayMenu();
void addBook();
void viewBooks();
void searchBook();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=============================\n");
    printf("  LIBRARY MANAGEMENT SYSTEM  \n");
    printf("=============================\n");
    printf("1. Add New Book\n");
    printf("2. View All Books\n");
    printf("3. Search Book by Title\n");
    printf("4. Exit\n");
    printf("=============================\n");
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &bookIDs[bookCount]);
    while (getchar() != '\n');

    printf("Enter Book Title: ");
    fgets(bookTitles[bookCount], STR_LEN, stdin);
    bookTitles[bookCount][strcspn(bookTitles[bookCount], "\n")] = '\0'; // Remove newline

    printf("Enter Author Name: ");
    fgets(bookAuthors[bookCount], STR_LEN, stdin);
    bookAuthors[bookCount][strcspn(bookAuthors[bookCount], "\n")] = '\0'; // Remove newline

    bookCount++;
    printf("\nBook added successfully!\n");
}

void viewBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-20s\n", "Book ID", "Title", "Author");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-20s\n", bookIDs[i], bookTitles[i], bookAuthors[i]);
    }
}

void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books available to search.\n");
        return;
    }

    char searchTitle[STR_LEN];
    int found = 0;

    printf("\nEnter Book Title to search: ");
    fgets(searchTitle, STR_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(bookTitles[i], searchTitle) == 0) {
            if (!found) {
                printf("\nBook Found:\n");
                printf("%-10s %-30s %-20s\n", "Book ID", "Title", "Author");
                printf("------------------------------------------------------------\n");
            }
            printf("%-10d %-30s %-20s\n", bookIDs[i], bookTitles[i], bookAuthors[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("\nBook with title '%s' not found.\n", searchTitle);
    }
}
