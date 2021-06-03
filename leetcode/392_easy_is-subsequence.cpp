class Solution {
public:
    bool isSubsequence(string s, string t) {
        // if(s.length() > t.length())
        //     return false;
        // if(s.length() == 0)
        //     return true;
        int i = 0;
        int j = 0;
        int m = s.length();
        int n = t.length();
        while(i < m && j < n && n-j >= m-i){
            if(s[i] == t[j])
                i++;
            j++;
    }
    return i == m;
    }
};