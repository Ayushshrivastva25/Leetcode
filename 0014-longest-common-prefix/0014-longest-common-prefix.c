char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";  // No strings given

    // We'll use the first string as a reference
    int i, j;
    for (i = 0; strs[0][i] != '\0'; i++) {
        char currentChar = strs[0][i];
        
        // Compare current character with each string
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != currentChar) {
                strs[0][i] = '\0';  // Truncate prefix
                return strs[0];
            }
        }
    }
    return strs[0];
}
