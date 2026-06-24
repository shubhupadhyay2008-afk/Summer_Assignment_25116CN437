#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicates(char *str) {
    bool seen[256] = { false };
    
    int writeIndex = 0;
    int readIndex = 0;

    while (str[readIndex] != '\0') {
        unsigned char currentChar = str[readIndex];
        if (!seen[currentChar]) {
            seen[currentChar] = true;
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }

    str[writeIndex] = '\0';
}

int main() {
    char str[] = "programming language";

    printf("Original String: %s\n", str);
    
    removeDuplicates(str);

    printf("After Removing Duplicates: %s\n", str);

    return 0;
}
