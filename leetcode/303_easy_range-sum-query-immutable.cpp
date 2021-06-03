class NumArray {
public:
vector <int>sums;

    NumArray(vector<int>& nums) {
        sums.push_back(0);
        // int prev = 0;
        for(int i=0; i<nums.size(); i++){
            // prev += nums[i];
            sums.push_back(nums[i]+sums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */