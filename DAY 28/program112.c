#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();

int main() {
    int choice;

    while (1) {
        system("cls||clear");
        printf("\n=================================");
        printf("\n   CONTACT MANAGEMENT SYSTEM   ");
        printf("\n=================================");
        printf("\n 1. Add Contact");
        printf("\n 2. View Contacts");
        printf("\n 3. Search Contact");
        printf("\n 4. Edit Contact");
        printf("\n 5. Delete Contact");
        printf("\n 6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Press Enter to try again.");
                getchar();
                getchar();
        }
    }
    return 0;
}

void addContact() {
    system("cls||clear");
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "ab");

    if (fp == NULL) {
        printf("\nError opening file!");
        return;
    }

    printf("\n--- Add New Contact ---");
    printf("\nEnter Name: ");
    scanf(" %[^\n]s", c.name);
    printf("Enter Phone: ");
    scanf(" %[^\n]s", c.phone);
    printf("Enter Email: ");
    scanf(" %[^\n]s", c.email);

    fwrite(&c, sizeof(struct Contact), 1, fp);
    fclose(fp);

    printf("\nContact added successfully! Press Enter to continue.");
    getchar();
    getchar();
}

void viewContacts() {
    system("cls||clear");
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "rb");

    if (fp == NULL) {
        printf("\nNo contacts found or error opening file!");
    } else {
        printf("\n--- Contact List ---\n");
        while (fread(&c, sizeof(struct Contact), 1, fp)) {
            printf("\nName: %s", c.name);
            printf("\nPhone: %s", c.phone);
            printf("\nEmail: %s", c.email);
            printf("\n--------------------");
        }
        fclose(fp);
    }

    printf("\nPress Enter to return to main menu.");
    getchar();
    getchar();
}

void searchContact() {
    system("cls||clear");
    char searchName[50];
    struct Contact c;
    int found = 0;
    FILE *fp = fopen("contacts.dat", "rb");

    if (fp == NULL) {
        printf("\nNo contacts found!");
    } else {
        printf("\n--- Search Contact ---");
        printf("\nEnter name to search: ");
        scanf(" %[^\n]s", searchName);

        while (fread(&c, sizeof(struct Contact), 1, fp)) {
            if (stricmp(c.name, searchName) == 0) { // Note: use strcasecmp on Linux/Mac instead of stricmp
                printf("\nContact Found:\n");
                printf("\nName: %s", c.name);
                printf("\nPhone: %s", c.phone);
                printf("\nEmail: %s", c.email);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nContact not found.");
        }
        fclose(fp);
    }
    
    printf("\nPress Enter to return to main menu.");
    getchar();
    getchar();
}

void editContact() {
    system("cls||clear");
    char editName[50];
    struct Contact c;
    int found = 0;
    FILE *fp = fopen("contacts.dat", "r+b");

    if (fp == NULL) {
        printf("\nNo contacts found!");
    } else {
        printf("\n--- Edit Contact ---");
        printf("\nEnter name of contact to edit: ");
        scanf(" %[^\n]s", editName);

        while (fread(&c, sizeof(struct Contact), 1, fp)) {
            if (stricmp(c.name, editName) == 0) {
                printf("\nEnter New Details:");
                printf("\nEnter Name: ");
                scanf(" %[^\n]s", c.name);
                printf("Enter Phone: ");
                scanf(" %[^\n]s", c.phone);
                printf("Enter Email: ");
                scanf(" %[^\n]s", c.email);

                fseek(fp, -sizeof(struct Contact), SEEK_CUR);
                fwrite(&c, sizeof(struct Contact), 1, fp);
                found = 1;
                break;
            }
        }
        if (found) {
            printf("\nContact updated successfully!");
        } else {
            printf("\nContact not found.");
        }
        fclose(fp);
    }

    printf("\nPress Enter to return to main menu.");
    getchar();
    getchar();
}

void deleteContact() {
    system("cls||clear");
    char delName[50];
    struct Contact c;
    int found = 0;
    FILE *fp = fopen("contacts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("\nError opening file!");
    } else {
        printf("\n--- Delete Contact ---");
        printf("\nEnter name of contact to delete: ");
        scanf(" %[^\n]s", delName);

        while (fread(&c, sizeof(struct Contact), 1, fp)) {
            if (stricmp(c.name, delName) == 0) {
                found = 1;
                continue;
            }
            fwrite(&c, sizeof(struct Contact), 1, temp);
        }
        fclose(fp);
        fclose(temp);

        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");

        if (found) {
            printf("\nContact deleted successfully!");
        } else {
            printf("\nContact not found.");
        }
    }

    printf("\nPress Enter to return to main menu.");
    getchar();
    getchar();
}
