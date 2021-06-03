class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector <int>count(60, 0);
        for(int i=0; i<n; i++){
            count[time[i] % 60] += 1;            
        }
        int pair_num = count[0] * (count[0]-1)/2 +  count[30] * (count[30]-1)/2;
        for(int i=1; i<30; i++){
            pair_num += count[i]* count[60-i];
        }
        
        return pair_num;
    }
};