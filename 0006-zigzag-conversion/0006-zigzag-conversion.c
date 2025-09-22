#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) {
        char* out = (char*)malloc(len + 1);
        strcpy(out, s);
        return out;
    }

    char **rows = (char**)malloc(numRows * sizeof(char*));
    int *rowLen = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc(len + 1);
        rows[i][0] = '\0';
    }

    int curRow = 0;
    int goingDown = 1;
    for (int i = 0; i < len; i++) {
        rows[curRow][rowLen[curRow]++] = s[i];
        rows[curRow][rowLen[curRow]] = '\0';

        if (curRow == 0) goingDown = 1;
        else if (curRow == numRows - 1) goingDown = 0;

        curRow += goingDown ? 1 : -1;
    }

    char* out = (char*)malloc(len + 1);
    int pos = 0;
    for (int i = 0; i < numRows; i++) {
        memcpy(out + pos, rows[i], rowLen[i]);
        pos += rowLen[i];
        free(rows[i]);
    }
    out[len] = '\0';

    free(rows);
    free(rowLen);

    return out;
}
