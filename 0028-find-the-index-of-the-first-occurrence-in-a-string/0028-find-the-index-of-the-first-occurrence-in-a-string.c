int strStr(char* haystack, char* needle) {
    int i, j;
    

    int hayLen = 0, needleLen = 0;
    while (haystack[hayLen] != '\0') hayLen++;
    while (needle[needleLen] != '\0') needleLen++;

    
    if (needleLen == 0) return 0;


    if (needleLen > hayLen) return -1;

    
    for (i = 0; i <= hayLen - needleLen; i++) {
        for (j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needleLen) {
            return i; 
        }
    }

    
    return -1;
}
