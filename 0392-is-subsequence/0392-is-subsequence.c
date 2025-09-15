#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int i = 0, j = 0;
    int lenS = strlen(s);
    int lenT = strlen(t);

    
    while (i < lenS && j < lenT) {
        if (s[i] == t[j]) {
            i++;  
        }
        j++;      
    }


    return i == lenS;
}
