#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void createArray(int arr[], int *size);
void displayArray(const int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(const int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0; 
    int choice;

    do {
        printf("\n=================================");
        printf("\n   ARRAY OPERATIONS MENU SYSTEM   ");
        printf("\n=================================");
        printf("\n1. Create / Initialize Array");
        printf("\n2. Display Array Elements");
        printf("\n3. Insert an Element");
        printf("\n4. Delete an Element");
        printf("\n5. Search for an Element");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                searchElement(arr, size);
                break;
            case 6:
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

void createArray(int arr[], int *size) {
    printf("\nEnter the number of elements to initialize (Max %d): ", MAX_SIZE);
    scanf("%d", size);

    if (*size < 0 || *size > MAX_SIZE) {
        printf("Error: Invalid size! Resetting size to 0.\n");
        *size = 0;
        return;
    }

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array initialized successfully.\n");
}

void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty! Nothing to display.\n");
        return;
    }

    printf("\nCurrent Array Elements:\n");
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("\nError: Array Overflow! Cannot insert more elements.\n");
        return;
    }

    int element, position;
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (0 to %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("Error: Invalid position!\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\nError: Array Underflow! No elements to delete.\n");
        return;
    }

    int position;
    printf("\nEnter the position of the element to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Error: Invalid position!\n");
        return;
    }

    int deletedValue = arr[position];

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element %d deleted successfully from position %d.\n", deletedValue, position);
}

void searchElement(const int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty! Nothing to search.\n");
        return;
    }

    int target, foundIndex = -1;
    printf("\nEnter the element to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Success: Element %d found at position (index) %d.\n", target, foundIndex);
    } else {
        printf("Failed: Element %d not found in the array.\n", target);
    }
}
