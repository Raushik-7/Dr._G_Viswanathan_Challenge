class Solution {
public:
    void lpsFind(vector<int>& lps, string s) {
        int pre = 0, suf = 1;
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++, suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int KMP_MATCH(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        int first = 0, second = 0;
        lpsFind(lps,needle);
        while (second < needle.size() && first < haystack.size()) {
            if (haystack[first] == needle[second]) {
                first++, second++;
            } else {
                if (second == 0) {
                    first++;
                } else {
                    second = lps[second - 1];
                }
            }
        }
        if (second == needle.size())
            return 1;
        else
            return 0;
    }

    int repeatedStringMatch(string a, string b) {

        // Check if a is equal to b
        if (a == b) {
            return 1;
        }

        // Repeat a until size is greater or equal to b
        string temp = a;
        int repeat = 1;
        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        // Match with b - KMP
        if (KMP_MATCH(temp, b) == 1) {
            return repeat;
        }
        // If not matched add one more time and match
        if (KMP_MATCH(temp + a, b) == 1) {
            return repeat + 1;
        }

        // If not matched till now
        return -1;
    }
};
