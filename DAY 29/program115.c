#include <stdio.h>

int getStringLength(char str[]);
void copyString(char dest[], char src[]);
void concatenateStrings(char dest[], char src[]);
int compareStrings(char str1[], char str2[]);
void reverseString(char str[]);

int main() {
    char str1[100], str2[100], dest[200];
    int choice, result;

    while (1) {
        printf("\n--- String Operations Menu ---\n");
        printf("1. Find Length of a String\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Reverse a String\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%[^\n]", str1);
                printf("Length of the string: %d\n", getStringLength(str1));
                break;

            case 2:
                printf("Enter source string: ");
                scanf("%[^\n]", str1);
                copyString(dest, str1);
                printf("Copied string: %s\n", dest);
                break;

            case 3:
                printf("Enter first string: ");
                scanf("%[^\n]", str1);
                while (getchar() != '\n');
                printf("Enter second string: ");
                scanf("%[^\n]", str2);
                
                copyString(dest, str1);
                concatenateStrings(dest, str2);
                printf("Concatenated string: %s\n", dest);
                break;

            case 4:
                printf("Enter first string: ");
                scanf("%[^\n]", str1);
                while (getchar() != '\n'); 
                printf("Enter second string: ");
                scanf("%[^\n]", str2);
                
                result = compareStrings(str1, str2);
                if (result == 0) {
                    printf("Strings are equal.\n");
                } else if (result > 0) {
                    printf("First string is greater than the second string.\n");
                } else {
                    printf("Second string is greater than the first string.\n");
                }
                break;

            case 5:
                printf("Enter a string to reverse: ");
                scanf("%[^\n]", str1);
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

int getStringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void concatenateStrings(char dest[], char src[]) {
    int i = 0;
    int j = 0;
    
    while (dest[i] != '\0') {
        i++;
    }
    
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void reverseString(char str[]) {
    int len = getStringLength(str);
    int start = 0;
    int end = len - 1;
    char temp;
    
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
}
