#include <stdio.h>
#include <string.h>

int checkAnagram(const char *str1, const char *str2) {
    int frequency[256] = {0};
    int i;

    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    for (i = 0; str1[i] != '\0'; i++) {
        frequency[(unsigned char)str1[i]]++;
        frequency[(unsigned char)str2[i]]--;
    }

    for (i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    char string1[100];
    char string2[100];

    printf("Enter the first string: ");
    scanf("%99s", string1);

    printf("Enter the second string: ");
    scanf("%99s", string2);

    if (checkAnagram(string1, string2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", string1, string2);
    } else {
        printf("\"%s\" and \"%s\" are not anagrams.\n", string1, string2);
    }

    return 0;
}
