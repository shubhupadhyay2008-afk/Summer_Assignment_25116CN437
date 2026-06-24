#include <stdio.h>
#include <string.h>

void compressString(const char *input, char *output) {
    int i = 0;
    int j = 0;
    int len = strlen(input);

    if (len == 0) {
        output[0] = '\0';
        return;
    }

    while (i < len) {
        output[j++] = input[i];
        
        int count = 1;
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        j += sprintf(&output[j], "%d", count);
        
        i++;
    }
    
    output[j] = '\0'; 
}

int main() {
    char str[100];
    char compressed[200];

    printf("Enter a string to compress: ");
    scanf("%99[^\n]", str); 

    compressString(str, compressed);

    if (strlen(compressed) < strlen(str)) {
        printf("Compressed string: %s\n", compressed);
    } else {
        printf("Compression does not reduce size. Original string: %s\n", str);
    }

    return 0;
}
