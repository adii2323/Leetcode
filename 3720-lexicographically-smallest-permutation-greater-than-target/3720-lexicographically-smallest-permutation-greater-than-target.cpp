class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        int l=0;
        vector<int>match_freq=freq;
        while (l<n && match_freq[target[l]-'a']> 0) {
            match_freq[target[l]-'a']--;
            l++;
        }
        int start_i = min(n-1,l);
        for (int i = l - 1; i >= start_i; i--) {
            match_freq[target[i] - 'a']++;
        }
        for (int i = start_i; i >= 0; i--) {
            int target_char = target[i] - 'a';
            for (int c = target_char + 1; c < 26; c++) {
                if (match_freq[c] > 0) {
                    string res = target.substr(0, i);
                    res += (char)('a' + c);
                    match_freq[c]--;
                    for (int j = 0; j < 26; j++) {
                        while (match_freq[j] > 0) {
                            res += (char)('a' + j);
                            match_freq[j]--;
                        }
                    }
                    return res;
                }
            }
            if (i > 0) {
                match_freq[target[i - 1] - 'a']++;
            }
        }
        return "";
    }
};