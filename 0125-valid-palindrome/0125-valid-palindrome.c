#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare lowercase characters
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
