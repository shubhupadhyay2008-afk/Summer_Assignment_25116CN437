#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIMIT 200

int main() {
    char sentence[MAX_LIMIT];
    int i = 0, current_len = 0, max_len = 0;
    int start_index = 0, max_start_index = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    while (sentence[i] != '\0') {
        if (!isspace((unsigned char)sentence[i]) && sentence[i] != '\n') {
            if (current_len == 0) {
                start_index = i;
            }
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                max_start_index = start_index;
            }
            current_len = 0;
        }
        i++;
    }

    if (current_len > max_len) {
        max_len = current_len;
        max_start_index = start_index;
    }
    printf("\nThe longest word is: ");
    for (i = 0; i < max_len; i++) {
        printf("%c", sentence[max_start_index + i]);
    }
    printf("\nLength of the longest word: %d\n", max_len);

    return 0;
}
