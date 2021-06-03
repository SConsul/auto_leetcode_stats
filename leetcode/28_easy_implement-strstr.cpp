class Solution {
public:
    int strStr(string haystack, string needle) {
        cout<<size(needle)<<endl;
        if(size(needle) == 0)
            return 0;
        if(size(haystack) == 0 )
            return -1;
        int n = size(haystack);
        int m = size(needle);
        bool flag = false;
        for (int i=0; i<n;i++){
            if(haystack[i] == needle[0]){
                flag = true;
                for(int j=i+1;j<m+i; j++){
                    if(haystack[j] != needle[j-i]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                return i;
            }
    return -1;
    }
};