#include <stdio.h>
#include <string.h>
#include <ctype.h>

void binary_to_decimal(char arr[], int len) {
    unsigned long long count = 0;

    for (int i = 0; i < len; i++) {
        // Calculate power of 2 by shifting
        count = count * 2 + (arr[i] - '0');  // 每次乘以 2 並加上當前位的數值
    }

    printf("%s is a binary number, %llu\n", arr, count);

}

void asc2(char arr[], int len) {
    for (int j = 0; j < len; j++) {
        if (arr[j] == '0' || arr[j] == '1'|| arr[j] == '2' || arr[j] == '3' || arr[j] == '4' || arr[j] == '5' || arr[j] == '6' || arr[j] == '7' || arr[j] == '8' || arr[j] == '9') {
            putchar(arr[j]);  // Print numbers as it is
        } else if (isalpha(arr[j])) {
            putchar(tolower(arr[j]));  // Convert letters to lowercase
        } else if (isspace(arr[j])) {
            printf("%%32");  // Space character in ASCII is 32
        } else {
            // Print ASCII code for other special characters
            printf("%%%d", arr[j]);
        }
    }
    printf(" is not a binary number\n");
}

int main() {
    char input[100];
    //printf("Enter input: ");
    scanf("%[^\n]%*c", input);  // Read the entire line including spaces

    int len = strlen(input);
    int flag = 0; // 0 means it’s a binary number, 1 means it’s not

    // Check if the input is binary
    for (int i = 0; i < len; i++) {
        if (input[i] != '0' && input[i] != '1') {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        binary_to_decimal(input, len);
    } else {
        asc2(input, len);
    }

    return 0;
}
