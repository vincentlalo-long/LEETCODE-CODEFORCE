#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    
    // The max length of the result is the max length of a or b + 1 (for a possible carry)
    int maxLen = (i > j ? i : j) + 2; 
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    
    result[maxLen] = '\0'; // Null-terminate the end
    int k = maxLen - 1;    // Pointer for the result string
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        if (i >= 0) sum += a[i--] - '0'; // Convert char to int
        if (j >= 0) sum += b[j--] - '0';
        
        result[k--] = (sum % 2) + '0'; // Result digit (0 or 1)
        carry = sum / 2;               // Update carry
    }

    // Since we started from the end of the allocated buffer, 
    // we return a pointer to the start of the actual string.
    return &result[k + 1];
}