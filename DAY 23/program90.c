#include <stdio.h>
#include <string.h>

char findFirstRepeating(char str[]) {
    int visited[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        if (visited[ch] == 1) {
            return str[i];
        }

        visited[ch] = 1;
    }

    return '\0'; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}
