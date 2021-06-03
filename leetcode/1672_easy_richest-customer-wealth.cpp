class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int m = accounts.size();
       int n = accounts[0].size();
       int max_wealth = 0;
        int wealth;
        for(int i=0; i < m; i ++){
            wealth = 0;
            for(int j=0; j < n; j++){
                wealth += accounts[i][j];
            }
            if(wealth > max_wealth)
                max_wealth = wealth;
               
        }
        return max_wealth;
    }
};