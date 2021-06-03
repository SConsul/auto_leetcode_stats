class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> cumsum;
        cumsum.push_back(nums[0]);
            for(int i=0; i < nums.size()-1; i++){
                int sum = nums[i+1] + cumsum[i];
                cumsum.push_back(sum);
            }
        return cumsum;
    }
};