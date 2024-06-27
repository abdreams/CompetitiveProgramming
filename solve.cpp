string getSmallestString(string word, string substr) {
    int num = word.size();
    int m = substr.size();

    int k = -1;
    for (int i = 0; i <= num - m; ++i) {
        bool possible = true;
        for (int j = 0; j < m; ++j) {
            if (word[i + j] != '?' && word[i + j] != substr[j]) {
                possible = false;
                break;
            }
        }
        if (possible) k = i;
    }

    if (k != -1) {
        int ct = 0;
        while (k < num && ct < m) {
            word[k] = substr[ct];
            ct++;
            k++;
        }
        for (int j = 0; j < num; ++j) {
            if (word[j] == '?') {
                word[j] = 'a';
            }
        }
        return word;
    }
    return "-1";
}   