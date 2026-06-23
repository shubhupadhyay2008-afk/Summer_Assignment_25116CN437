#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define ASCII_SIZE 256

int main() {
    char str[MAX_SIZE];
    int freq[ASCII_SIZE] = {0};
    int max_count = 0;
    char max_char = ' ';

    printf("Enter any string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char index = (unsigned char)str[i];
        freq[index]++;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char index = (unsigned char)str[i];
        if (freq[index] > max_count) {
            max_count = freq[index];
            max_char = str[i];
        }
    }

    if (max_count > 0) {
        printf("The maximum occurring character is '%c' with a frequency of %d.\n", max_char, max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
