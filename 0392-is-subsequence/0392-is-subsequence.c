#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int i = 0, j = 0;
    int lenS = strlen(s);
    int lenT = strlen(t);

    // Traverse both strings
    while (i < lenS && j < lenT) {
        if (s[i] == t[j]) {
            i++;  // move to next char in s if a match is found
        }
        j++;      // always move forward in t
    }

    // If all characters in s were matched
    return i == lenS;
}
