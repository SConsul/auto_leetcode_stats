class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i <nums.size(); i++) {
            for (int j=i+1; j <nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    vector<int> v{i,j};
                    return v;
                }  
            }
        }
        vector<int> v{-1};
        return v;
    }
};