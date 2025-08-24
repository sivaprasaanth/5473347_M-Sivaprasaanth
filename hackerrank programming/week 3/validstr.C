char* isValid(char* s) {
    static char yes[] = "YES";
    static char no[] = "NO";
    int freq[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    int f[26], count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            f[count++] = freq[i];
        }
    }
    int min = f[0], max = f[0];
    for (int i = 1; i < count; i++) {
        if (f[i] < min) min = f[i];
        if (f[i] > max) max = f[i];
    }
    int minCount = 0, maxCount = 0;
    for (int i = 0; i < count; i++) {
        if (f[i] == min) minCount++;
        else if (f[i] == max) maxCount++;
    }
    if (min == max) return yes;
    else if (minCount == count - 1 && max - min == 1) return yes;
    else if (maxCount == count - 1 && min == 1) return yes;
    return no;

}