#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * 1000);
    *returnSize = 0;

    int i = 0;
    while (i < wordsSize) {
        int lineLength = strlen(words[i]);
        int j = i + 1;

        while (j < wordsSize && lineLength + 1 + strlen(words[j]) <= maxWidth) {
            lineLength += 1 + strlen(words[j]);
            j++;
        }

        int numWords = j - i;
        int totalChars = 0;
        for (int k = i; k < j; k++)
            totalChars += strlen(words[k]);

        int totalSpaces = maxWidth - totalChars;
        char* line = (char*)malloc(sizeof(char) * (maxWidth + 1));
        int pos = 0;

        if (j == wordsSize || numWords == 1) {
            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);
                memcpy(line + pos, words[k], len);
                pos += len;
                if (pos < maxWidth)
                    line[pos++] = ' ';
            }
            while (pos < maxWidth)
                line[pos++] = ' ';
        } else {
            int spacesBetween = totalSpaces / (numWords - 1);
            int extraSpaces = totalSpaces % (numWords - 1);

            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);
                memcpy(line + pos, words[k], len);
                pos += len;

                if (k < j - 1) {
                    int spacesToAdd = spacesBetween + (k - i < extraSpaces ? 1 : 0);
                    for (int s = 0; s < spacesToAdd; s++)
                        line[pos++] = ' ';
                }
            }
        }

        line[pos] = '\0';
        result[*returnSize] = line;
        (*returnSize)++;
        i = j;
    }

    return result;
}
