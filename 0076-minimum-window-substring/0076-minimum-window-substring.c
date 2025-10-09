#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int need[128] = {0}, window[128] = {0};
    int required = 0;

    // Build frequency map for t
    for (int i = 0; t[i]; i++) {
        if (need[t[i]] == 0)
            required++;
        need[t[i]]++;
    }

    int have = 0, left = 0, right = 0;
    int start = 0, minLen = INT_MAX;
    int lenS = strlen(s);

    // Expand the right pointer
    while (right < lenS) {
        char c = s[right];
        window[c]++;

        if (need[c] > 0 && window[c] == need[c])
            have++;

        // Try to shrink from the left
        while (have == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            char d = s[left];
            window[d]--;
            if (need[d] > 0 && window[d] < need[d])
                have--;
            left++;
        }

        right++;
    }

    if (minLen == INT_MAX)
        return "";

    // Copy the smallest substring
    char* res = (char*)malloc(minLen + 1);
    strncpy(res, s + start, minLen);
    res[minLen] = '\0';
    return res;
}
