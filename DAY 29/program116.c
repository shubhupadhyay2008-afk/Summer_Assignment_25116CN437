#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define FILE_NAME "inventory.txt"

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void menu();
void addProduct();
void displayInventory();
void updateStock();
void searchProduct();
void loadInventory();
void saveInventory();

Product inventory[MAX_ITEMS];
int item_count = 0;

int main() {
    int choice;
    
    loadInventory();

    do {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                saveInventory();
                printf("Data saved successfully. Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void menu() {
    printf("\n===================================\n");
    printf("    INVENTORY MANAGEMENT SYSTEM    \n");
    printf("===================================\n");
    printf("1. Add New Product\n");
    printf("2. Display All Products\n");
    printf("3. Update Stock Quantity\n");
    printf("4. Search Product by ID\n");
    printf("5. Save and Exit\n");
    printf("===================================\n");
}

void addProduct() {
    if (item_count >= MAX_ITEMS) {
        printf("Error: Inventory capacity full!\n");
        return;
    }

    Product p;
    printf("Enter Product ID (Integer): ");
    scanf("%d", &p.id);
    
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == p.id) {
            printf("Error: A product with ID %d already exists!\n", p.id);
            return;
        }
    }

    printf("Enter Product Name: ");
    while (getchar() != '\n'); 
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Price: ");
    scanf("%f", &p.price);

    inventory[item_count] = p;
    item_count++;
    printf("Product added successfully!\n");
}

void displayInventory() {
    if (item_count == 0) {
        printf("\nYour inventory is currently empty.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("--------------------------------------------------------- \n");
    for (int i = 0; i < item_count; i++) {
        printf("%-10d %-25s %-10d $%-9.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateStock() {
    int id, found = 0;
    printf("Enter Product ID to update stock: ");
    scanf("%d", &id);

    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            printf("Current quantity for %s: %d\n", inventory[i].name, inventory[i].quantity);
            printf("Enter new stock quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Stock updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}
void searchProduct() {
    int id, found = 0;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            printf("\nProduct Found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: $%.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void loadInventory() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return;
    }

    item_count = 0;
    while (fscanf(file, "%d\n", &inventory[item_count].id) != EOF) {
        fgets(inventory[item_count].name, sizeof(inventory[item_count].name), file);
        inventory[item_count].name[strcspn(inventory[item_count].name, "\n")] = 0; // Strip newline
        fscanf(file, "%d %f\n", &inventory[item_count].quantity, &inventory[item_count].price);
        item_count++;
        
        if (item_count >= MAX_ITEMS) break;
    }
    fclose(file);
}

void saveInventory() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error: Could not open file to save data.\n");
        return;
    }

    for (int i = 0; i < item_count; i++) {
        fprintf(file, "%d\n%s\n%d %.2f\n", 
                inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
}
