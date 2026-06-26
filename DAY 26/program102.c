#include <stdio.h>

int main() {
    int age;
    char citizen;

    printf("Enter your age: ");
    scanf("%d", &age);
    
    printf("Are you a citizen? (y/n): ");
    scanf(" %c", &citizen); 

    // Check voting criteria
    if (age >= 18 && (citizen == 'y' || citizen == 'Y')) {
        printf("Congratulations, you are eligible to vote!\n");
    } else {
        printf("Sorry, you are not eligible to vote.\n");
    }

    return 0;
}
