class Solution {
public:
    int countVowelStrings(int n) {
        int mat[n][5];
        int i,j;
        for(i=0; i<n; i++)
            mat[i][0] = 1;
        for (i=0;i<5;i++)
            mat[0][i] = i+1;
        for (i=1; i<n;i++){
            for(j=1;j<5;j++){
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        return mat[n-1][4];
    }
};