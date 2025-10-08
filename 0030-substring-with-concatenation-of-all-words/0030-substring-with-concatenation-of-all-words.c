#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} WordCount;

int findWordIndex(WordCount *arr, int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].word, word) == 0)
            return i;
    }
    return -1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (!s || !words || wordsSize == 0) return NULL;

    int sLen = strlen(s);
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;

    if (sLen < totalLen) return NULL;

    // Step 1: Build frequency map for words
    WordCount *original = malloc(sizeof(WordCount) * wordsSize);
    int uniqueCount = 0;

    for (int i = 0; i < wordsSize; i++) {
        int idx = findWordIndex(original, uniqueCount, words[i]);
        if (idx == -1) {
            original[uniqueCount].word = words[i];
            original[uniqueCount].count = 1;
            uniqueCount++;
        } else {
            original[idx].count++;
        }
    }

    // Result array (max possible size = sLen)
    int *result = malloc(sizeof(int) * sLen);
    int resultCount = 0;

    // Step 2: Sliding window
    for (int offset = 0; offset < wordLen; offset++) {
        int left = offset;
        int count = 0;

        // Create temporary counts
        WordCount *seen = malloc(sizeof(WordCount) * uniqueCount);
        for (int i = 0; i < uniqueCount; i++) {
            seen[i].word = original[i].word;
            seen[i].count = 0;
        }

        for (int j = offset; j + wordLen <= sLen; j += wordLen) {
            char word[wordLen + 1];
            strncpy(word, s + j, wordLen);
            word[wordLen] = '\0';

            int idx = findWordIndex(original, uniqueCount, word);

            if (idx != -1) {
                seen[idx].count++;
                count++;

                // Too many occurrences
                while (seen[idx].count > original[idx].count) {
                    char leftWord[wordLen + 1];
                    strncpy(leftWord, s + left, wordLen);
                    leftWord[wordLen] = '\0';

                    int leftIdx = findWordIndex(original, uniqueCount, leftWord);
                    if (leftIdx != -1) {
                        seen[leftIdx].count--;
                        count--;
                    }
                    left += wordLen;
                }

                // If we found a valid window
                if (count == wordsSize) {
                    result[resultCount++] = left;

                    // Move left forward
                    char leftWord[wordLen + 1];
                    strncpy(leftWord, s + left, wordLen);
                    leftWord[wordLen] = '\0';

                    int leftIdx = findWordIndex(original, uniqueCount, leftWord);
                    if (leftIdx != -1) {
                        seen[leftIdx].count--;
                        count--;
                    }
                    left += wordLen;
                }
            } else {
                // Reset window
                for (int k = 0; k < uniqueCount; k++) seen[k].count = 0;
                count = 0;
                left = j + wordLen;
            }
        }

        free(seen);
    }

    free(original);

    *returnSize = resultCount;
    return result;
}
