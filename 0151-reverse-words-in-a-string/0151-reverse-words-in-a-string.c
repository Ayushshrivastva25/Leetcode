char* reverseWords(char* s) {
    int n = strlen(s);
    char *temp = (char*)malloc(n + 1); 
    int idx = 0;

    
    int i = 0;
    while (i < n && s[i] == ' ') i++;

    
    for (; i < n; i++) {
        if (s[i] != ' ') {
            temp[idx++] = s[i];
        } else if (idx > 0 && temp[idx - 1] != ' ') {
            temp[idx++] = ' ';
        }
    }

    
    if (idx > 0 && temp[idx - 1] == ' ') idx--;
    temp[idx] = '\0';

    
    if (idx == 0) return temp;

    
    void reverse(char *str, int l, int r) {
        while (l < r) {
            char tmp = str[l];
            str[l++] = str[r];
            str[r--] = tmp;
        }
    }

    
    reverse(temp, 0, idx - 1);

    
    int start = 0;
    for (int j = 0; j <= idx; j++) {
        if (temp[j] == ' ' || temp[j] == '\0') {
            reverse(temp, start, j - 1);
            start = j + 1;
        }
    }

    return temp;
}
